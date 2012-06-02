#include "TarFile.hpp"

#include <QFile>
#include <QFileInfo>
#include <QDateTime>

#include <stdexcept>

TarFile::TarFile():
    header_(TAR_HEADER_SIZE, '\0'),
    isValid_(false)
{
    setHeader_(MODE, QByteArray::number(0644, 8).rightJustified(MODE_SIZE - 1, '0', true));
    setHeader_(SIZE, QByteArray::number(0).rightJustified(SIZE_SIZE - 1, '0', true));
    setHeader_(MTIME, QByteArray::number(QDateTime::currentDateTime().toTime_t(), 8).rightJustified(MTIME_SIZE - 1, '0', true));
    setHeader_(TYPEFLAG, "0");
    setHeader_(MAGIC, "ustar  ");
    calculateChecksum_();
}

TarFile::TarFile(const QString& name, const TarContent& content):
    header_(TAR_HEADER_SIZE, '\0'),
    isValid_(true)
{
    setHeader_(NAME, name.leftJustified(NAME_SIZE, '\0', true).toAscii());
    setHeader_(MODE, QByteArray::number(0644, 8).rightJustified(MODE_SIZE - 1, '0', true));
    setHeader_(MTIME, QByteArray::number(QDateTime::currentDateTime().toTime_t(), 8).rightJustified(MTIME_SIZE - 1, '0', true));
    setHeader_(TYPEFLAG, "0");
    setHeader_(MAGIC, "ustar  ");

    setContent(content);

    calculateChecksum_();

    if(name.isEmpty())
    {
        isValid_ = false;
    }
}

QString TarFile::name() const
{
    return header_.mid(NAME, NAME_SIZE);
}

std::size_t TarFile::size() const
{
    return header_.mid(SIZE, SIZE_SIZE).toULongLong(0, 8);
}

const TarHeader& TarFile::header() const
{
    return header_;
}

const TarContent& TarFile::content() const
{
    return content_;
}

void TarFile::setContent(const TarContent &content)
{
    content_ = content;
    setHeader_(SIZE, QByteArray::number(content.size(), 8).rightJustified(SIZE_SIZE - 1, '0', true));
}

TarFile TarFile::fromHeader(const TarHeader& header)
{
    TarFile tarFile;

    tarFile.header_ = header;

    QByteArray chksum = tarFile.header_.mid(CHKSUM, CHKSUM_SIZE);
    tarFile.calculateChecksum_();
    if(chksum != tarFile.header_.mid(CHKSUM, CHKSUM_SIZE))
    {
        // TODO error
        throw std::logic_error("");
    }

    tarFile.content_.rightJustified(tarFile.size(), '\0');

    if(! tarFile.name().isEmpty())
    {
        tarFile.isValid_ = true;
    }

    return tarFile;
}

TarFile TarFile::fromFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // TODO error
        throw std::logic_error("");
    }

    QByteArray content = file.readAll();

    file.close();

    QFileInfo fileInfo(fileName);

    TarFile tarFile(fileInfo.fileName(), content);

    tarFile.setHeader_(MTIME, QByteArray::number(fileInfo.lastModified().toTime_t(), 8).rightJustified(MTIME_SIZE - 1, '0', true));
    tarFile.calculateChecksum_();

    return tarFile;
}

void TarFile::setHeader_(std::size_t offset, const QByteArray &data)
{
    header_.replace(offset, data.size(), data);
}

void TarFile::calculateChecksum_()
{
    setHeader_(CHKSUM, QByteArray(CHKSUM_SIZE, ' '));

    int sum = 0;
    for(int i = 0; i < TAR_HEADER_SIZE; ++i)
    {
        sum += header_[i];
    }

    /*for(int i = CHKSUM; i < CHKSUM_SIZE; ++i)
    {
        sum += ' ' - header_[i];
    }*/

    setHeader_(CHKSUM, QByteArray::number(sum, 8).rightJustified(CHKSUM_SIZE - 2, '0').append('\0'));
}

bool TarFile::isValid() const
{
    return isValid_;
}

