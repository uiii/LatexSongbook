#include "TarFile.hpp"

#include <QFile>
#include <QFileInfo>
#include <QDateTime>

TarFile::TarFile():
    header_(TAR_HEADER_SIZE, '\0')
{
    setHeader(MAGIC, "ustar");
    calculateChecksum_();
}

TarHeader TarFile::header()
{
    return header_;
}

TarContent TarFile::content()
{
    return content_;
}

void TarFile::setHeader(std::size_t offset, const QByteArray &data)
{
    header_.replace(offset, data.size(), data);
}

void TarFile::setContent(const TarContent &content)
{
    content_ = content;
}

TarFile TarFile::fromFile(const QString& fileName)
{
    TarFile tarFile;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return tarFile; // TODO error
    }

    QByteArray content = file.readAll();
    content.append(QByteArray(content.size() % 512, '\0'));

    file.close();

    QFileInfo fileInfo(fileName);

    tarFile.setHeader(NAME, fileInfo.fileName().leftJustified(NAME_SIZE, '\0', true).toAscii());
    tarFile.setHeader(MODE, QByteArray::number(0644, 8).rightJustified(MODE_SIZE - 1, '0', true));
    tarFile.setHeader(MTIME, QByteArray::number(fileInfo.lastModified().toTime_t(), 8).rightJustified(MTIME_SIZE - 1, '0', true));
    tarFile.setHeader(TYPEFLAG, "0");
    tarFile.calculateChecksum_();

    tarFile.setContent(content);

    return tarFile;
}

void TarFile::calculateChecksum_()
{
    int sum = 0;
    for(int i = 0; i < TAR_HEADER_SIZE; ++i)
    {
        sum += header_[i];
    }

    for(int i = CHKSUM; i < CHKSUM_SIZE; ++i)
    {
        sum += ' ' - header_[i];
    }

    setHeader(CHKSUM, QByteArray::number(sum, 8).leftJustified(CHKSUM_SIZE - 2, '0'));
}

