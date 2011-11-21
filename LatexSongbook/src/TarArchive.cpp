#include "TarArchive.hpp"

#include <QFileInfo>
#include <QDataStream>

TarArchive::TarArchive(const QString& fileName):
    archiveFile_(fileName)
{
    if(QFileInfo(archiveFile_).exists())
    {
        load_();
    }
}

void TarArchive::addFile(TarFile file)
{
    tarFiles_.append(file);
}

void TarArchive::pack()
{
    if(! archiveFile_.open(QIODevice::WriteOnly))
    {
        return; // TODO error
    }

    QDataStream output(&archiveFile_);
    for(TarFile& tarFile : tarFiles_)
    {
        output << tarFile.header();
        output << tarFile.content();
    }

    QByteArray emptyBlock(TAR_BLOCK_SIZE, '\0');
    output << emptyBlock << emptyBlock;

    archiveFile_.close();
}

void TarArchive::extract(const QString &path)
{
    for(TarFile& tarFile : tarFiles_)
    {
        // TODO
    }
}

void TarArchive::load_()
{
    if(! archiveFile_.open(QIODevice::ReadOnly))
    {
        return; // TODO error
    }

    archiveFile_.reset();

    TarFile tarFile;
    QByteArray block;
    block.reserve(512);
    while(! archiveFile_.atEnd())
    {
        tarFile.setHeader(0, readBlock_(TAR_HEADER_SIZE));

        // TODO zjistit z velikosti souboru kolik bloku nacist
        //tarFile.content_ = readBlock_(TAR_BLOCK_SIZE);

        tarFiles_.append(tarFile);
    }

    archiveFile_.close();
}

QByteArray TarArchive::readBlock_(std::size_t size)
{
    QByteArray block = archiveFile_.read(size);
    if((std::size_t)block.size() < size)
    {
        block.append(QByteArray(block.size() % size, '\0'));
    }

    return block;
}
