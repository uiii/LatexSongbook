#ifndef TARARCHIVE_HPP
#define TARARCHIVE_HPP

#include <QFile>
#include <QList>

#include "TarFile.hpp"

class TarArchive
{
public:
    TarArchive(const QString& fileName);

    void addFile(const TarFile& file);
    void addFiles(const QList<TarFile>& file);

    void pack();
    void extract(const QString& path = ".");

private:
    void load_();
    QByteArray readBlock_(std::size_t size);

    QFile archiveFile_;
    QList<TarFile> tarFiles_;
};

#endif // TARARCHIVE_HPP
