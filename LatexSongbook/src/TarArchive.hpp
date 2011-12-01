#ifndef TARARCHIVE_HPP
#define TARARCHIVE_HPP

#include <QFile>
#include <QMap>

#include "TarFile.hpp"

class TarArchive
{
public:
    TarArchive(const QString& fileName);

    void addFile(const TarFile& file);
    const QMap<TarFile>& files();

    void pack();
    void extract(const QString& path = ".");

private:
    void load_();
    QByteArray readBlock_(std::size_t size);

    QFile archiveFile_;
    QMap<TarFile> tarFiles_;
};

#endif // TARARCHIVE_HPP
