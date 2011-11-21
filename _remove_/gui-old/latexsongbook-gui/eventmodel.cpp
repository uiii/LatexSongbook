#include "eventmodel.h"

#include <QBrush>

EventModel::EventModel(QObject *parent) :
    QAbstractListModel(parent),
    highlightNow_(false)
{
}

int EventModel::rowCount(const QModelIndex&) const
{
    if(dataSource_)
    {
        return dataSource_->size() + 1;
    }
    else
    {
        return 1;
    }
}

QVariant EventModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= rowCount(QModelIndex()))
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        if(index.row() == rowCount(QModelIndex()) - 1)
        {
            if(highlightNow_)
            {
                return "Now *";
            }
            else
            {
                return "Now";
            }
        }
        else
        {
            auto fileTime = dataSource_->at(index.row());
            char timeStr[256];
            struct tm* timeInfo = localtime(&fileTime);
            std::strftime(timeStr, 256, "%x - %X", timeInfo);

            return timeStr;
        }
    }
    else if(role == Qt::ForegroundRole)
    {
        if(index.row() == rowCount(QModelIndex()) - 1 && highlightNow_)
        {
            return QBrush(Qt::red);
        }
        else
        {
            return QBrush(Qt::black);
        }
    }
    else
    {
        return QVariant();
    }
}

void EventModel::update()
{
    reset();
}

void EventModel::setDataSource(EventList *events)
{
    dataSource_ = events;
}

std::time_t EventModel::rawData(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return 0;
    }

    if (index.row() >= rowCount(QModelIndex()))
    {
        return 0;
    }

    if(index.row() == rowCount(QModelIndex()) - 1)
    {
        return 0;
    }
    else
    {
        return dataSource_->at(index.row());
    }
}

void EventModel::highlightNow(bool flag)
{
    highlightNow_ = flag;
}
