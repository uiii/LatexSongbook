#include "LocalDatabaseModel.hpp"

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>
#include <QModelIndex>

SongInfo::SongInfo():
    isValid(false)
{
}

LocalDatabaseModel::LocalDatabaseModel(QObject* parent):
    QStandardItemModel(parent)
{
    setHorizontalHeaderLabels(QStringList()
        << tr("name")
        << tr("author")
        << tr("file")
        << tr("last changed")
    );

    setSortRole(Qt::UserRole + 1);

    watcher_ = new QFileSystemWatcher();

    connect(watcher_, SIGNAL(directoryChanged(QString)), this, SLOT(reloadSongs()));
    connect(watcher_, SIGNAL(fileChanged(QString)), this, SLOT(reloadSongs()));
}

SongInfo LocalDatabaseModel::songInfo(const QModelIndex& index)
{
    if(! index.isValid())
    {
        throw;
    }

    return songs_.at(index.row());
}

void LocalDatabaseModel::setDirectory(const QString &path)
{
    path_ = path;

    if(path_.isEmpty())
    {
        return;
    }

    watcher_->addPath(path_);

    reloadSongs();
}

void LocalDatabaseModel::reloadSongs()
{
    if(! QFileInfo(path_).isDir())
    {
        emit invalidDirectory();
    }

    SongInfoList::Iterator songIt = songs_.begin();

    QDir dir(path_);
    QFileInfoList entries = dir.entryInfoList(QDir::Files, QDir::Name | QDir::LocaleAware);
    QFileInfoList::Iterator entryIt = entries.begin();

    while(songIt != songs_.end() && entryIt != entries.end())
    {
        //qDebug() << songIt->file.fileName();
        //qDebug() << entryIt->fileName();
        if(QString::localeAwareCompare(songIt->file.fileName(), entryIt->fileName()) < 0)
        {
            // remove

            songIt = removeSongInfo_(songIt);
        }
        else if(songIt->file.fileName() == entryIt->fileName())
        {
            if(songIt->lastModified != entryIt->lastModified())
            {
                // update

                SongInfo songInfo;
                try
                {
                    songInfo = loadSongInfo_(*entryIt);
                }
                catch(...)
                {
                    songIt = removeSongInfo_(songIt);
                }

                if(songInfo.isValid)
                {
                    updateSongInfo_(songIt, songInfo);
                    ++songIt;
                }
            }
            else
            {
                ++songIt;
            }

            ++entryIt;
        }
        else
        {
            // new

            SongInfo songInfo;
            try
            {
                songInfo = loadSongInfo_(*entryIt);
            }
            catch(...)
            {
            }

            if(songInfo.isValid)
            {
                songIt = newSongInfo_(songIt, songInfo);
            }

            ++entryIt;
        }
    }

    //qDebug() << "tady";

    while(songIt != songs_.end())
    {
        // remove

        songIt = removeSongInfo_(songIt);
    }

    while(entryIt != entries.end())
    {
        // new

        SongInfo songInfo;
        try
        {
            songInfo = loadSongInfo_(*entryIt);
        }
        catch(...)
        {
            //qDebug() << "catch";
        }

        if(songInfo.isValid)
        {
            songIt = newSongInfo_(songIt, songInfo);
        }

        ++entryIt;
        //qDebug() << "pass";
    }

    qDebug() << "emit songs reloaded";
    emit songsReloaded();
}

SongInfo LocalDatabaseModel::loadSongInfo_(QFileInfo fileInfo) const
{
    //qDebug() << fileInfo.absoluteFilePath();
    QFile file(fileInfo.absoluteFilePath());
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw 1; // TODO warning
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    QString line = stream.readLine();

    //qDebug() << line;

    QRegExp reg("(\\S.+) +\\((\\S.+)\\) *");
    if(! reg.exactMatch(line))
    {
        throw 1; // TODO warning
    }

    QString name = reg.cap(1);
    QString author = reg.cap(2);

    SongInfo songInfo;

    songInfo.file = fileInfo;
    songInfo.name = name;
    songInfo.author = author;
    songInfo.lastModified = fileInfo.lastModified();
    songInfo.isValid = true;

    //qDebug() << songInfo.file.fileName();
    //qDebug() << songInfo.name;
    //qDebug() << songInfo.author;
    //qDebug() << songInfo.lastChanged;

    return songInfo;
}

LocalDatabaseModel::SongInfoList::Iterator LocalDatabaseModel::removeSongInfo_(SongInfoList::Iterator it)
{
    watcher_->removePath(it->file.absoluteFilePath());

    for(QStandardItem* item : takeRow(it - songs_.begin()))
    {
        delete item;
    }

    return songs_.erase(it);
}

void LocalDatabaseModel::updateSongInfo_(SongInfoList::Iterator it, SongInfo songInfo)
{
    QStandardItem* nameItem = new QStandardItem(songInfo.name);
    nameItem->setData(songInfo.name);
    QStandardItem* authorItem = new QStandardItem(songInfo.author);
    authorItem->setData(songInfo.author);
    QStandardItem* fileItem = new QStandardItem(songInfo.file.fileName());
    fileItem->setData(songInfo.file.fileName());
    QStandardItem* lastModifiedItem = new QStandardItem(songInfo.lastModified.toString("dd.MM.yyyy   hh:mm:ss"));
    lastModifiedItem->setData(songInfo.lastModified);

    int row = it - songs_.begin();

    setItem(row, 0, nameItem);
    setItem(row, 1, authorItem);
    setItem(row, 2, fileItem);
    setItem(row, 3, lastModifiedItem);
}

LocalDatabaseModel::SongInfoList::Iterator LocalDatabaseModel::newSongInfo_(SongInfoList::Iterator it, SongInfo songInfo)
{
    watcher_->addPath(songInfo.file.absoluteFilePath());

    QStandardItem* nameItem = new QStandardItem(songInfo.name);
    nameItem->setData(songInfo.name);
    QStandardItem* authorItem = new QStandardItem(songInfo.author);
    authorItem->setData(songInfo.author);
    QStandardItem* fileItem = new QStandardItem(songInfo.file.fileName());
    fileItem->setData(songInfo.file.fileName());
    QStandardItem* lastModifiedItem = new QStandardItem(songInfo.lastModified.toString("dd.MM.yyyy   hh:mm:ss"));
    lastModifiedItem->setData(songInfo.lastModified);

    insertRow(it - songs_.begin(), QList<QStandardItem*>()
        << nameItem << authorItem << fileItem << lastModifiedItem
    );

    it = songs_.insert(it, songInfo);
    ++it;
    return it;
}
