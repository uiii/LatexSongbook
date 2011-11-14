#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QStringList>

#include "song.h"
#include "songfilter.h"
#include "common.h"

class SongModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SongModel();
    ~SongModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void sort();
    void sort(int column, Qt::SortOrder order);

    void setDataSource(SongList* songList);

    //void addSongs(SongList song);
    //void addSong(Song* song);

    void setFilter(SongFilter* filter);

    //const SongList& songs() const;

signals:

public slots:
    void update();

private:
    QStringList headerData_;
    SongList songList_;

    SongList* dataSource_;

    int sortColumn_;
    Qt::SortOrder sortOrder_;

    SongFilter* filter_;
};

#endif // SONGMODEL_H
