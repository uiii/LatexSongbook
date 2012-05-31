#ifndef TARARCHIVE_HPP
#define TARARCHIVE_HPP

#include <QFile>
#include <QMap>

#include "TarFile.hpp"

class TarArchive
{
public:
    typedef QMap<QString, TarFile> Files;

    TarArchive(const QString& fileName);

    void addFile(const TarFile& file);
    const Files& files() const;

    void pack();
    void extract(const QString& path = ".");

private:
    void load_();
    QByteArray readBlock_(std::size_t size);

    QFile archiveFile_;
    QMap<QString, TarFile> tarFiles_;
};

#endif // TARARCHIVE_HPP
