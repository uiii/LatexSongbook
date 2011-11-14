#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H

#include <QAbstractListModel>

#include "common.h"

class InstrumentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit InstrumentModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role) const;
    Instrument* rawData(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;

    void setDataSource(InstrumentList* instruments);
signals:

public slots:
    void update();

private:
    InstrumentList* dataSource_;
};


#endif // INSTRUMENTMODEL_H
