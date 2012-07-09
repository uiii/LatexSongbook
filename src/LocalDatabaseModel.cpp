#include "LocalDatabaseModel.hpp"

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>
#include <QModelIndex>

LocalDatabaseModel::LocalDatabaseModel(const QString& path, QObject* parent):
    QStandardItemModel(parent),
    dir_(path)
{
    if(! QFileInfo(dir_.absolutePath()).isDir())
    {
        throw; // TODO error
    }

    setHorizontalHeaderLabels(QStringList()
        << tr("name")
        << tr("author")
        << tr("file")
        << tr("last changed")
    );

    setSortRole(Qt::UserRole + 1);

    watcher_ = new QFileSystemWatcher();
    watcher_->addPath(dir_.absolutePath());
    connect(watcher_, SIGNAL(directoryChanged(QString)), this, SLOT(updateSongs()));
    connect(watcher_, SIGNAL(fileChanged(QString)), this, SLOT(updateSongs()));

    updateSongs();
}

SongInfo LocalDatabaseModel::songInfo(const QModelIndex& index)
{
    if(! index.isValid())
    {
        throw;
    }

    return songs_.at(index.row());
}

void LocalDatabaseModel::updateSongs()
{
    SongInfoList::Iterator songIt = songs_.begin();
    int songRow = 0;

    for(QFileInfo fileInfo : dir_.entryInfoList(QDir::Files, QDir::Name | QDir::LocaleAware))
    {
        qDebug() << fileInfo.fileName();
        if(songIt != songs_.end()) qDebug() << "->" << songIt->file.fileName();
        while(songIt != songs_.end() && QString::localeAwareCompare(songIt->file.fileName(), fileInfo.fileName()) < 0)
        {
            qDebug() << "move";

            watcher_->removePath(songIt->file.absoluteFilePath());

            songIt = songs_.erase(songIt);

            for(QStandardItem* item : takeRow(songRow))
            {
                delete item;
            }

            songRow++;
        }

        watcher_->addPath(fileInfo.absoluteFilePath());

        bool update = true;
        bool newSong = false;
        if(songIt != songs_.end() && songIt->file.fileName() == fileInfo.fileName())
        {
            if(songIt->lastChanged == fileInfo.lastModified())
            {
                // not need to update
                update = false;
            }
        }
        else
        {
            newSong = true;
        }

        if(update)
        {
            SongInfo songInfo;
            try
            {
                songInfo = loadSongInfo_(fileInfo);
            }
            catch(...)
            {
                continue; // TODO warning
            }

            if(newSong)
            {
                songIt = songs_.insert(songIt, songInfo);
                insertRow(songRow);
            }

            updateSongInfo_(songRow, songInfo);
        }

        songIt++;
        songRow++;
    }
}

SongInfo LocalDatabaseModel::loadSongInfo_(QFileInfo fileInfo) const
{
    QFile file(fileInfo.absoluteFilePath());
    if(! file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw 1; // TODO warning
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    QString line = stream.readLine();

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
    songInfo.lastChanged = fileInfo.lastModified();

    //qDebug() << songInfo.file.fileName();
    //qDebug() << songInfo.name;
    //qDebug() << songInfo.author;
    //qDebug() << songInfo.lastChanged;

    return songInfo;
}

void LocalDatabaseModel::updateSongInfo_(int row, SongInfo songInfo)
{
    QStandardItem* nameItem = new QStandardItem(songInfo.name);
    nameItem->setData(songInfo.name);
    QStandardItem* authorItem = new QStandardItem(songInfo.author);
    authorItem->setData(songInfo.author);
    QStandardItem* fileItem = new QStandardItem(songInfo.file.fileName());
    fileItem->setData(songInfo.file.fileName());
    QStandardItem* lastChangeItem = new QStandardItem(songInfo.lastChanged.toString("dd.MM.yyyy   hh:mm:ss"));
    lastChangeItem->setData(songInfo.lastChanged);

    setItem(row, 0, nameItem);
    setItem(row, 1, authorItem);
    setItem(row, 2, fileItem);
    setItem(row, 3, lastChangeItem);
}
