#include "SongParser.hpp"

#include <QRegExp>
#include <QTextStream>
#include <QDebug>
#include <QStringList>

SongParser::SongParser():
    parsed_(false)
{

}

void SongParser::parse(const QString &text)
{
    clear_();

    originalText_ = text;

    QTextStream stream(&originalText_);
    QString line = stream.readLine();

    QRegExp reg("(\\S.+) +\\((\\S.+)\\) *");
    if(! reg.exactMatch(line))
    {
        // TODO error
    }
    else
    {
        name_ = reg.cap(1);
        author_ = reg.cap(2);
    }

    text_ = stream.readAll();
}

bool SongParser::noErrors() const
{
    parseText_();

    return errors_.isEmpty();
}

QString SongParser::name() const
{
    return name_;
}

QString SongParser::author() const
{
    return author_;
}

QList<SongParser::Section> SongParser::sections() const
{
    parseText_();

    if(noErrors())
    {
        return sections_;
    }
    else
    {
        return QList<Section>();
    }
}

QList<SongParser::Message> SongParser::errors() const
{
    parseText_();

    return errors_;
}

QList<SongParser::Message> SongParser::warnings() const
{
    parseText_();

    return warnings_;
}

void SongParser::clear_()
{
    name_ = QString();
    author_ = QString();
    text_ = QString();

    parsed_ = false;

    sections_.clear();
    errors_.clear();
    warnings_.clear();
}

void SongParser::parseText_() const
{
    if(parsed_)
    {
        return;
    }

    QList<Chord> chordBuffer;
    Section* currentSection = nullptr;

    int lineNumber = 1;

    QString text = text_;
    QTextStream stream(&text);
    while(! stream.atEnd())
    {
        ++lineNumber;

        QString line = stream.readLine();

        QRegExp emptyLineExp(" *");
        QRegExp lyricsLineExp("( +)(.+)");
        QRegExp chordsLineExp("((:+) +)(.+)");
        QRegExp newSectionLineExp("(([^\\.]*)\\. +)(.+)");

        if(emptyLineExp.exactMatch(line))
        {
            // skip empty line
        }
        else if(lyricsLineExp.exactMatch(line))
        {
            parseLyricsLine_(lyricsLineExp.cap(2), lineNumber, chordBuffer, currentSection, lyricsLineExp.cap(1).size());
        }
        else if(chordsLineExp.exactMatch(line))
        {
            parseChordLine_(chordsLineExp.cap(3), lineNumber, chordBuffer, currentSection, chordsLineExp.cap(1).size());

            if(chordsLineExp.cap(2).size() > 1)
            {
                newChordSection_(chordBuffer, currentSection);
            }
        }
        else if(newSectionLineExp.exactMatch(line))
        {
            newSection_(newSectionLineExp.cap(2), currentSection);

            parseLyricsLine_(newSectionLineExp.cap(3), lineNumber, chordBuffer, currentSection, newSectionLineExp.cap(1).size());
        }
        else
        {
            Message error = { lineNumber, "Syntax error." };
            errors_.push_back(error);
        }
    }

    QTextStream output;
    for(Section s : sections_)
    {
        qDebug() << "section";
        for(Line l : s.lines)
        {
            qDebug() << "line";
            if(! l.chords.isEmpty()) qDebug() << l.chords.first().offset;
            qDebug() << l.lyrics;
        }
    }

    parsed_ = true;
}

void SongParser::newSection_(const QString& sectionLabel, SongParser::Section*& currentSection) const
{
    QRegExp verseExp("[0-9]+");
    QRegExp refrainExp("Ref( ([0-9]+))?");
    QRegExp recitationExp("Rec( ([0-9]+))?");

    Section section;

    if(sectionLabel.isEmpty())
    {
        section.type = Unmarked;
    }
    else if(verseExp.exactMatch(sectionLabel))
    {
        section.type = Verse;
        section.detail = sectionLabel;
    }
    else if(refrainExp.exactMatch(sectionLabel))
    {
        section.type = Refrain;
        section.detail = refrainExp.cap(2);
    }
    else if(recitationExp.exactMatch(sectionLabel))
    {
        section.type = Recitation;
        section.detail = recitationExp.cap(2);
    }
    else
    {
        section.type = Label;
        section.detail = sectionLabel;
    }

    sections_.push_back(section);
    currentSection = &sections_.back();
}

void SongParser::newChordSection_(QList<Chord>& chordBuffer, Section*& currentSection) const
{
    Line line = {chordBuffer, ""};

    Section section = {ChordsLine, QString(), {line}};
    sections_.push_back(section);

    currentSection = nullptr;

    chordBuffer.clear();
}

void SongParser::parseLyricsLine_(const QString& lyrics, int lineNumber, QList<Chord>& chordBuffer, Section*& currentSection, int offset) const
{
    if(! currentSection)
    {
        Message error = { lineNumber, "You must started some song's section before lyrics line." };
        errors_.push_back(error);

        return;
    }

    if(! chordBuffer.isEmpty())
    {
        chordBuffer.first().offset -= offset;
        if(chordBuffer.first().offset < 0)
        {
            Message error = { lineNumber - 1, "Chord cannot be before lyrics line beginning." };
            errors_.push_back(error);
        }
    }

    Line line = {chordBuffer, lyrics};
    currentSection->lines.push_back(line);

    chordBuffer.clear();
}

void SongParser::parseChordLine_(const QString& line, int lineNumber, QList<SongParser::Chord>& chordBuffer, Section*& currentSection, int offset) const
{
    if(! chordBuffer.isEmpty())
    {
        Message warning = { lineNumber, "Lyrics expected. Previous chords line will be ignored." };
        warnings_.push_back(warning);

        chordBuffer.clear();
    }

    QRegExp chordExp("( *)([^ ]+)");

    int lastChordNameSize = 0;
    int pos = 0;
    while ((pos = chordExp.indexIn(line, pos)) != -1)
    {
        Chord chord = { lastChordNameSize + chordExp.cap(1).size(), chordExp.cap(2) };
        chordBuffer.append(chord);

        lastChordNameSize = chord.name.size();
        pos += chordExp.matchedLength();
    }

    chordBuffer.first().offset += offset;

    for(Chord ch : chordBuffer) // remove
    {
        qDebug() << ch.offset << ": " << ch.name;
    }
}
