#include "songbook.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdexcept>

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QtAlgorithms>

#include <songbooksituation.h>
#include <songcomparator.h>

Songbook::Songbook():
    //currentSituation_(unfiledSongs_, filedSongs_)
    instrument_(0),
    instrumentSettings_(0)
{
    //updateEventList_();
}

void Songbook::clear()
{
    bool unfiledEmpty = unfiledSongs_.empty();
    bool filedEmpty = filedSongs_.empty();
    bool eventsEmpty = eventList_.empty();

    unfiledSongs_.clear();
    filedSongs_.clear();
    eventList_.clear();

    if(instrumentSettings_)
    {
        instrumentSettings_->setCurrentInstrument("");
        updateInstrument();
    }

    if(! unfiledEmpty) emit unfiledChanged();
    if(! filedEmpty) emit filedChanged();
    if(! eventsEmpty) emit eventsChanged();
}

bool Songbook::load(const QString& filename)
{
    QFile songbookFile(filename);

    if(!songbookFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false; // TODO chybova hlaska

    QTextStream songbookStream(&songbookFile);
    QString songbookContent = songbookStream.readAll();

    QRegExp songbookSyntax(
                "instrument:[ \\t]*([\\w\\-]*)\n"
                "songs:(|\\n.*)"
    );

    if(! songbookSyntax.exactMatch(songbookContent))
    {
        QString error = filename + ": Songbook file invalid syntax";
        throw std::runtime_error(error.toAscii().data());
    }

    QString instrumentName = songbookSyntax.cap(1);
    QString songs = songbookSyntax.cap(2);

    if(instrumentSettings_)
    {
        if(instrumentSettings_->setCurrentInstrument(instrumentName))
        {
            updateInstrument();
        }
        else
        {
            QString error = filename + ": unknown instrument '" + instrumentName + "'";
            throw std::runtime_error(error.toAscii().data());
        }
    }

    QTextStream songsStream(&songs);
    while(! songsStream.atEnd())
    {
        QString line = songsStream.readLine();

        if(line == "")
        {
            continue;
        }

        QRegExp songInfo("BEGIN>>>\\[([\\d]+)\\]");
        if(! songInfo.exactMatch(line))
        {
            QString error = filename + ": Songbook file invalid syntax: Expected 'BEGIN>>>' but get '" + line + "'";
            throw std::runtime_error(error.toAscii().data());
        }

        std::time_t fileTime = songInfo.cap(1).toLong();

        QString data;
        QTextStream dataStream(&data);

        line = songsStream.readLine();
        while(line != "<<<END")
        {
            dataStream << line << "\n";
            line = songsStream.readLine();
        }

        try
        {
            Song* song = new Song(data, fileTime);

            filedSongs_.push_back(song);
        }
        catch(const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    songbookFile.close();

    qStableSort(filedSongs_.begin(), filedSongs_.end(), SongComparator< SongProperty<std::time_t>::type >(&Song::fileTime, Qt::AscendingOrder));

    std::time_t fileTime = 0;
    for(auto it = filedSongs_.begin(); it != filedSongs_.end(); ++it)
    {
        if((*it)->fileTime() != fileTime)
        {
            fileTime = (*it)->fileTime();

            eventList_.push_back(fileTime);
        }
    }

    emit filedChanged();
    emit eventsChanged();

    return true;
}

SongList& Songbook::songs()
{
    return filedSongs_;
}

/*SongbookSituation Songbook::situation(std::time_t fileTime)
{
    SongList newSongs;
    SongList songs;

    SongList::iterator it;
    for(it = filedSongs_.begin(); it != filedSongs_.end(); ++it)
    {
        if((*it)->fileTime() == fileTime)
        {
            newSongs.push_back(*it);
            songs.push_back(*it);
        }
        else if((*it)->fileTime() < fileTime)
        {
            songs.push_back(*it);
        }
    }

    return SongbookSituation(newSongs, songs);
}*/

/*const QStringListModel& Songbook::events()
{
    return eventList_;
}*/

/*void Songbook::updateEventList_()
{
    qStableSort(filedSongs_.begin(), filedSongs_.end(), SongComparator< SongProperty<std::time_t>::type >(&Song::fileTime, Qt::AscendingOrder));

    std::time_t fileTime = 0;
    SongList::iterator it;
    for(it = filedSongs_.begin(); it != filedSongs_.end(); ++it)
    {
        if((*it)->fileTime() != fileTime)
        {
            fileTime = (*it)->fileTime();

            char timeStr[256];
            struct tm* timeInfo = localtime(&fileTime);
            std::strftime(timeStr, 256, "%x %X", timeInfo);

            eventList_.push_back(qMakePair(QString(timeStr), fileTime));
        }
    }

    eventList_.push_back(qMakePair(QString("Now"), (std::time_t) 0));
}*/

/*SongbookSituation& Songbook::currentSituation()
{
    return currentSituation_;
}*/

SongList & Songbook::unfiledSongs()
{
    return unfiledSongs_;
}

void Songbook::addSongs(QStringList songFileList)
{
    for(auto it = songFileList.begin(); it != songFileList.end(); ++it)
    {
        QFile songFile(*it);

        if(!songFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return; // TODO chybova hlaska

        QString data = songFile.readAll();

        try
        {
            Song* song = new Song(data);

            unfiledSongs_.push_back(song);
        }
        catch(const std::runtime_error& e)
        {
            std::cout << (*it).toAscii().data() << ": " << e.what() << std::endl;
        }

        songFile.close();
    }

    emit unfiledChanged();
}

bool Songbook::fileUnfiled()
{
    if(unfiledSongs_.size() == 0)
    {
        return false;
    }

    std::time_t fileTime = time(NULL);

    for(auto it = unfiledSongs_.begin(); it != unfiledSongs_.end(); ++it)
    {
        (*it)->file(fileTime);
        filedSongs_.push_back(*it);
    }

    unfiledSongs_.clear();

    eventList_.push_back(fileTime);

    emit unfiledChanged();
    emit filedChanged();
    emit eventsChanged();

    return true;
}

EventList & Songbook::events()
{
    return eventList_;
}

bool Songbook::save(const QString &filename)
{
    QFile songbookFile(filename);

    if(!songbookFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false; // TODO chybova hlaska

    QTextStream songbookStream(&songbookFile);

    songbookStream << "instrument: " << (instrument_ ? instrument_->name() : "") << "\n";
    songbookStream << "songs:";

    for(auto it = filedSongs_.begin(); it != filedSongs_.end(); ++it)
    {
        Song* song = *it;
        songbookStream << "\nBEGIN>>>[" << song->fileTime() << "]\n" << song->data() << "<<<END";
    }

    songbookFile.close();

    return true;
}

void Songbook::setInstrument(Instrument *instrument)
{
    instrument_ = instrument;
}

Instrument * Songbook::instrument()
{
    return instrument_;
}

void Songbook::updateInstrument()
{
    instrument_ = instrumentSettings_->currentInstrument();

    emit instrumentChanged(instrument_ ? instrument_->name() : "-- No instrument --");
}

void Songbook::setInstrumentSettings(InstrumentSettings *instrumentSettings)
{
    instrumentSettings_ = instrumentSettings;
}

const QString & Songbook::paperSize()
{
    return paperSize_;
}

const QString & Songbook::fontSize()
{
    return fontSize_;
}

void Songbook::setPaperSize(const QString &size)
{
    bool changed = (paperSize_ != size);

    paperSize_ = size;

    if(changed)
    {
        emit sizeChanged();
    }
}

void Songbook::setFontSize(const QString &size)
{
    bool changed = (fontSize_ != size);

    fontSize_ = size;

    if(changed)
    {
        emit sizeChanged();
    }
}
