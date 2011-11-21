#include "Database.hpp"

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFileSystemWatcher>

#include <QtSql/QSqlDatabase>

Database::Database(QObject *parent) :
    QObject(parent)
{
    database_ = QSqlDatabase::addDatabase("QSQTILE");
    database_.setDatabaseName("database.db");
    if(! database_.open())
    {
        // TODO error
    }

    connect(&watcher_, SIGNAL(directoryChanged(QString)), this, updateDirectory(QString));
}

void Database::addDirectory(const QString &path)
{
    QFileInfo dirInfo(path);
    if(! dirInfo.isDir())
    {
        // TODO error;
        return;
    }

    watcher_.addPath(dirInfo.canonicalFilePath());
    updateDirectory(dirInfo.canonicalFilePath());
}

void Database::updateDirectory(const QString &path)
{
    QFileInfoList entries = QDir(path).entryInfoList();
    QFileInfo entry;
    for(QFileInfo& entry : entries)
    {
        if(entry.isDir())
        {
            addDirectory(entry.canonicalFilePath());
        }
        else if(entry.isFile())
        {
            // TODO update file
        }
    }
}
