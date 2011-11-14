#include "song.h"

#include <QTextStream>
#include <QRegExp>
#include <QStringList>

#include <iostream>
#include <stdexcept>

/*Song::Song(const QString& title, const QString& author):
    title_(title),
    author_(author),
    fileTime_(0)
{
}*/

Song::Song(const QString& data, std::time_t fileTime):
    fileTime_(fileTime),
    data_(data)
{
    QTextStream stream(&data_);
    QString header = stream.readLine();

    QRegExp reg("(.+) \\((.+)\\)");
    if(! reg.exactMatch(header))
    {
        QString error = QString("Invalid song syntax: ") + header;
        throw std::runtime_error(error.toAscii().data());
    }

    reg.indexIn(header);

    title_ = reg.cap(1);
    author_ = reg.cap(2);
}

/*Song::Song(const QString& title, const QString& author, std::time_t time, const QString& data):
    title_(title),
    author_(author),
    fileTime_(time),
    data_(data)
{
}*/

const QString & Song::title() const
{
    return title_;
}

const QString & Song::author() const
{
    return author_;
}

std::time_t Song::fileTime() const
{
    return fileTime_;
}

bool Song::isFiled() const
{
    return fileTime_ != 0;
}

void Song::file(std::time_t fileTime)
{
    fileTime_ = fileTime;
}

const QString & Song::data() const
{
    return data_;
}
