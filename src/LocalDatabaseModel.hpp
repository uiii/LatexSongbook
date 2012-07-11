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
    QFileInfo file;
    QString name;
    QString author;
    QDateTime lastChanged;
};

class LocalDatabaseModel : public QStandardItemModel
{
    Q_OBJECT

public:
    LocalDatabaseModel(const QString& path, QObject* parent = 0);

    SongInfo songInfo(const QModelIndex& index);

signals:
    
public slots:
    void reloadSongs();

private slots:

private:
    SongInfo loadSongInfo_(QFileInfo info) const;
    void updateSongInfo_(int row, SongInfo songInfo);

    QDir dir_;
    QFileSystemWatcher* watcher_;

    typedef QVector<SongInfo> SongInfoList;
    SongInfoList songs_;
};

#endif // LOCALDATABASEMODEL_HPP
