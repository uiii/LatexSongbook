#ifndef LOCALDATABASEMODEL_HPP
#define LOCALDATABASEMODEL_HPP

#include <QFileSystemWatcher>
#include <QStandardItemModel>
#include <QDir>
#include <QVector>
#include <QString>
#include <QDateTime>

struct SongInfo
{
    SongInfo();

    QFileInfo file;
    QString name;
    QString author;
    QDateTime lastModified;

    bool isValid;
};

class LocalDatabaseModel : public QStandardItemModel
{
    Q_OBJECT

public:
    LocalDatabaseModel(QObject* parent = 0);

    SongInfo songInfo(const QModelIndex& index);

    void setDirectory(const QString& path);

signals:
    void invalidDirectory();
    void songsReloaded();
    
public slots:
    void reloadSongs();

private:
    typedef QVector<SongInfo> SongInfoList;

    SongInfo loadSongInfo_(QFileInfo info) const;
    SongInfoList::Iterator removeSongInfo_(SongInfoList::Iterator it);
    void updateSongInfo_(SongInfoList::Iterator it, SongInfo songInfo);
    SongInfoList::Iterator newSongInfo_(SongInfoList::Iterator it, SongInfo songInfo);

    QString path_;
    QFileSystemWatcher* watcher_;

    SongInfoList songs_;
};

#endif // LOCALDATABASEMODEL_HPP
