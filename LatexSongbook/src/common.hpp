#ifndef COMMON_HPP
#define COMMON_HPP

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

bool removeDir(const QDir& dir)
{
    if(! dir.exists())
    {
        return true;
    }

    bool isRemoved = true;

    QFileInfoList entryList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for(QFileInfo& entry : entryList)
    {
        QString path = entry.absoluteFilePath();
        if(entry.isDir())
        {
            isRemoved = isRemoved && removeDir(QDir(path));
        }
        else
        {
            isRemoved = isRemoved && QFile(path).remove();
        }
    }

    return isRemoved && dir.rmdir(dir.absolutePath());
}

#endif // COMMON_HPP
