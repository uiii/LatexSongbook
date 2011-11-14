#include "songmodel.h"

#include <QtAlgorithms>

#include <iostream>

#include <songcomparator.h>

SongModel::SongModel():
    QAbstractListModel(0),
    sortColumn_(0),
    sortOrder_(Qt::AscendingOrder),
    filter_(new NoFilter())
{
    headerData_ << tr("Title") << tr("Author") << tr("Filed");
}

SongModel::~SongModel()
{
}

QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= songList_.size())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
            case 0:
                return songList_.at(index.row())->title();
                break;
            case 1:
                return songList_.at(index.row())->author();
                break;
            case 2:
            {
                auto fileTime = songList_.at(index.row())->fileTime();
                char timeStr[256];
                struct tm* timeInfo = localtime(&fileTime);
                std::strftime(timeStr, 256, "%x - %X", timeInfo);

                return songList_.at(index.row())->isFiled() ? timeStr : tr("no");
                break;
            }
            default:
                return "";
                break;
        }
    }
    else
    {
        return QVariant();
    }
}

int SongModel::rowCount(const QModelIndex&) const
{
    return songList_.size();
}

int SongModel::columnCount(const QModelIndex&) const
{
    return headerData_.size();
}

QVariant SongModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        return headerData_.at(section);
    }
    else
    {
        return section;
    }
}

/*void Songmodel::addSong(Song* song)
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex())+1);
    songList_.push_back(song);
    endInsertRows();
}

void Songmodel::addSongs(SongList songs)
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex())+songs.size());
    songList_.append(songs);
    endInsertRows();
}*/

void SongModel::sort()
{
    sort(sortColumn_, sortOrder_);
}

void SongModel::sort(int column, Qt::SortOrder order)
{
    sortColumn_ = column;
    sortOrder_ = order;

    update();
}

/*SongList Songmodel::filterSongs(std::time_t fileTime)
{
    SongList filteredList;

    SongList::const_iterator it;
    for(it = songList_.begin(); it != songList_.end(); ++it)
    {
        if((*it)->fileTime() == fileTime)
        {
            filteredList.push_back(*it);
        }
    }

    return filteredList;
}*/

/*const SongList & Songmodel::songs() const
{
    return songList_;
}*/

void SongModel::setFilter(SongFilter *filter)
{
    filter_ = filter;
}

void SongModel::setDataSource(SongList *songList)
{
    dataSource_ = songList;

    update();
}

void SongModel::update()
{
    beginResetModel();

    songList_.clear();

    for(auto it = dataSource_->begin(); it != dataSource_->end(); ++it)
    {
        if(filter_->check(*it))
        {
            songList_.push_back(*it);
        }
    }

    switch(sortColumn_)
    {
        case 0:
            qStableSort(songList_.begin(), songList_.end(), SongComparator< SongProperty<const QString&>::type >(&Song::title, sortOrder_));
            break;
        case 1:
            qStableSort(songList_.begin(), songList_.end(), SongComparator< SongProperty<const QString&>::type >(&Song::author, sortOrder_));
            break;
        case 2:
            qStableSort(songList_.begin(), songList_.end(), SongComparator< SongProperty<std::time_t>::type >(&Song::fileTime, sortOrder_));
            break;
        default:
            break;
    }

    endResetModel();
}
