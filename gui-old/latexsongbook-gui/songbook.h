#ifndef SONGBOOK_H
#define SONGBOOK_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QStringListModel>

#include "songmodel.h"
#include "songbooksituation.h"
#include "instrument.h"
#include "instrumentsettings.h"

//typedef QPair< QString, std::time_t> Event;
typedef QList<std::time_t> EventList;

class Songbook : public QObject
{
    Q_OBJECT

public:
    Songbook();
    //virtual ~Songbook() {}

    SongList& songs();
    SongList& unfiledSongs();

    EventList& events();

    Instrument* instrument();

    void clear();

    bool load(const QString& filename);
    bool save(const QString& filename);

    void addSongs(QStringList songFileList);

    const QString& paperSize();
    const QString& fontSize();

    void setInstrument(Instrument* instrument);
    void setInstrumentSettings(InstrumentSettings* instrumentSettings);
    //SongbookSituation situation(std::time_t fileTime);
    //SongbookSituation& currentSituation();

    //QStringListModel events();

public slots:
    bool fileUnfiled();
    void updateInstrument();

    void setPaperSize(const QString& size);
    void setFontSize(const QString& size);

private slots:

signals:
    void unfiledChanged();
    void filedChanged();
    void eventsChanged();
    void instrumentChanged(const QString&);
    void sizeChanged();

private:
    //void updateEventList_();

    QString paperSize_;
    QString fontSize_;

    SongList unfiledSongs_;
    SongList filedSongs_;

    EventList eventList_;

    Instrument* instrument_;
    InstrumentSettings* instrumentSettings_;
};

#endif // SONGBOOK_H
