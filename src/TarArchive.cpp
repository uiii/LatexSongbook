#include "TarArchive.hpp"

#include <QDir>
#include <QFileInfo>

TarArchive::TarArchive(const QString& fileName):
    archiveFile_(fileName)
{
    if(QFileInfo(archiveFile_).exists())
    {
        load_();
    }
}

void TarArchive::addFile(const TarFile& file)
{
    if(file.isValid())
    {
        tarFiles_[file.name()] = file;
    }
}

const TarArchive::Files& TarArchive::files() const
{
    return tarFiles_;
}

void TarArchive::pack()
{
    if(! archiveFile_.open(QIODevice::WriteOnly))
    {
        return; // TODO error
    }

    for(TarFile& tarFile : tarFiles_)
    {
        archiveFile_.write(tarFile.header());
        archiveFile_.write(tarFile.content());
        archiveFile_.write(QByteArray(TAR_BLOCK_SIZE - tarFile.content().size() % TAR_BLOCK_SIZE, '\0'));
    }

    QByteArray emptyBlock(TAR_BLOCK_SIZE, '\0');
    archiveFile_.write(emptyBlock);
    archiveFile_.write(emptyBlock);

    archiveFile_.close();
}

void TarArchive::extract(const QString &path)
{
    QDir dir(path);
    if(! dir.exists())
    {
        QDir().mkpath(path);
    }

    for(TarFile& tarFile : tarFiles_)
    {
        QFile file(dir.filePath(tarFile.name()));

        if(! file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return; // TODO error
        }

        file.write(tarFile.content());

        file.close();
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

    bool emptyBlock = false;
    while(! archiveFile_.atEnd())
    {
        QByteArray block = readBlock_(TAR_HEADER_SIZE);

        if(block[0] == '\0')
        {
            if(emptyBlock)
            {
                break;
            }
            else
            {
                emptyBlock = true;
                continue;
            }
        }


        TarFile tarFile = TarFile::fromHeader(block);

        TarContent content = readBlock_(tarFile.size());
        readBlock_(TAR_BLOCK_SIZE - tarFile.size() % TAR_BLOCK_SIZE);

        tarFile.setContent(content);

        addFile(tarFile);
    }

    archiveFile_.close();
}

QByteArray TarArchive::readBlock_(std::size_t size)
{
    QByteArray block = archiveFile_.read(size);
    block.append(QByteArray(size - block.size(), '\0'));

    return block;
}
