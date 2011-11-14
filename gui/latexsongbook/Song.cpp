#include "Song.hpp"

#include <QTextStream>
#include <QRegExp>
#include <QStringList>

#include <stdexcept>

Song::Song(QObject* parent, const QString& data, QDateTime fileTime):
    QObject(parent),
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

const QString & Song::title() const
{
    return title_;
}

const QString & Song::author() const
{
    return author_;
}

QDateTime Song::fileTime() const
{
    return fileTime_;
}

bool Song::isFiled() const
{
    return fileTime_.isValid();
}

void Song::file(QDateTime fileTime)
{
    fileTime_ = fileTime;
}

const QString & Song::data() const
{
    return data_;
}
