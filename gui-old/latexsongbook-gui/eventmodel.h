#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractListModel>

#include "common.h"

class EventModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit EventModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role) const;
    std::time_t rawData(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;

    void setDataSource(EventList* events);
signals:

public slots:
    void update();
    void highlightNow(bool);

private:
    EventList* dataSource_;

    bool highlightNow_;
};

#endif // EVENTMODEL_H
