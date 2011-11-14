#include "instrumentmodel.h"

#include <QFont>

#include <iostream>

InstrumentModel::InstrumentModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

QVariant InstrumentModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(index.row() >= rowCount(QModelIndex()))
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole)
    {
        if(index.row() == 0)
        {
            return tr("-- No instrument selected --");
        }
        else
        {
            return dataSource_->at(index.row() - 1)->name();
        }
    }

    return QVariant();
}

int InstrumentModel::rowCount(const QModelIndex&) const
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

void InstrumentModel::setDataSource(InstrumentList *instruments)
{
    dataSource_ = instruments;
}

Instrument* InstrumentModel::rawData(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return 0;
    }

    if (index.row() >= rowCount(QModelIndex()))
    {
        return 0;
    }

    /*if(index.row() == rowCount(QModelIndex()) - 1)
    {
        return 0;
    }
    else
    {
        return dataSource_->at(index.row());
    }*/

    return dataSource_->at(index.row());
}

void InstrumentModel::update()
{
    std::cout << "reset" << std::endl;
    reset();
}
