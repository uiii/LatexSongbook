#include "instrument.h"

#include <QFile>
#include <QTextStream>

#include <iostream>
#include <stdexcept>

Instrument::Instrument(
    const QString& instrumentFile,
    const QString& name,
    const QString& imageFile,
    int stringsCount,
    const QString& chordsDef,
    bool reportUnknownChords
):
    instrumentFile_(instrumentFile),
    name_(name),
    imageFile_(imageFile),
    stringsCount_(stringsCount),
    chordsDef_(chordsDef),
    reportUnknownChords_(reportUnknownChords)
{
}

void Instrument::setName(const QString &name)
{
    name_ = name;

    emit changed();
}

void Instrument::setImageFile(const QString &file)
{
    std::cout << file.toAscii().data() << std::endl;
    imageFile_ = file;

    emit changed();
}

void Instrument::setStringsCount(int count)
{
    stringsCount_ = count;

    emit changed();
}

void Instrument::setChordsDef(const QString &chordsDef)
{
    chordsDef_ = chordsDef;

    emit changed();
}

void Instrument::setReportUnknownChords(bool flag)
{
    reportUnknownChords_ = flag;

    emit changed();
}

const QString & Instrument::name() const
{
    return name_;
}

const QString & Instrument::imageFile() const
{
    return imageFile_;
}

int Instrument::stringsCount() const
{
    return stringsCount_;
}

const QString & Instrument::chordsDef() const
{
    return chordsDef_;
}

bool Instrument::reportUnknownChords() const
{
    return reportUnknownChords_;
}

void Instrument::save()
{
    QFile file(instrumentFile_);

    if(! file.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text))
    {
        QString error = QString("Cannot save '") + name_ + "' instrument: Cannot open file: " + instrumentFile_;
        throw std::runtime_error(error.toAscii().data());
    }

    QTextStream stream(&file);

    stream << "name: " << name_ << "\n";
    stream << "image: " << imageFile_ << "\n";
    stream << "stringsCount: " << stringsCount_ << "\n";
    stream << "reportUnknownChords: " << (reportUnknownChords_ ? "true" : "false") << "\n";
    stream << "chordsDef:\n" << chordsDef_;

    file.close();
}
