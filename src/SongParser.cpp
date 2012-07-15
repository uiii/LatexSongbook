#include "SongParser.hpp"

#include <QRegExp>
#include <QTextStream>
#include <QDebug>
#include <QStringList>

SongParser::SongParser(const QString &text):
    parsed_(false),
    originalText_(text)
{
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
}

bool SongParser::correct() const
{
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

QList<SongParser::Section> SongParser::sections()
{
    if(! parsed_)
    {
        parseText_();
    }

    if(correct())
    {
        return sections_;
    }
    else
    {
        return QList<Section>();
    }
}

void SongParser::parseText_()
{
    QList<Chord> chordBuffer;
    Section* currentSection = nullptr;

    QTextStream stream(&originalText_);
    while(! stream.atEnd())
    {
        QString line = stream.readLine();

        if(line.isEmpty())
        {
            continue;
        }

        switch(line.toAscii().at(0))
        {
            case ' ': parseLyricsLine_(line, chordBuffer, currentSection);
            break;
            case ':': parseChordLine_(line, chordBuffer, currentSection);
            break;
            case '.': parseUnmarkedSectionLine_(line, chordBuffer, currentSection);
            break;
            case '*': parseStarSectionLine_(line, chordBuffer, currentSection);
            break;
            case 'R': parseNamedSectionLine_(line, chordBuffer, currentSection);
            break;
            default: parseNumberedSectionLine_(line, chordBuffer, currentSection);
            break;
        }
    }

    QTextStream output;
    for(Section s : sections_)
    {
        qDebug() << "section";
        for(Line l : s.lines)
        {
            qDebug() << "line";
            qDebug() << l.lyrics;
        }
    }
}

void SongParser::parseLyricsLine_(QString& lyrics, QList<Chord>& chordBuffer, Section*& currentSection, int offset)
{
    if(! currentSection)
    {
        // TODO error
        return;
    }

    int pos = 0;
    while(lyrics.at(pos) == ' ')
    {
        ++pos;
    }

    if(! chordBuffer.isEmpty())
    {
        chordBuffer.first().offset -= offset + pos;
        if(chordBuffer.first().offset < 0)
        {
            // TODO error - chord cannot be before lyrics beginning
        }
    }

    Line line = {chordBuffer, lyrics.mid(pos)};
    currentSection->lines.push_back(line);
}

void SongParser::parseChordLine_(QString& line, QList<SongParser::Chord>& chordBuffer, Section*& currentSection)
{
    if(! chordBuffer.isEmpty())
    {
        // TODO warning - chord line after another one

        chordBuffer.clear();
    }

    QRegExp lineExp("(:+)( [^:]+)");
    if(! lineExp.exactMatch(line))
    {
        // TODO error
        return;
    }

    QString colons = lineExp.cap(1);
    line = lineExp.cap(2);

    QRegExp chordExp("( +)([^ ]+)");

    int pos = 0;
    while ((pos = chordExp.indexIn(line, pos)) != -1)
    {
        Chord chord = { chordExp.cap(1).size(), chordExp.cap(2) };
        chordBuffer.append(chord);

        pos += chordExp.matchedLength();
    }

    chordBuffer.first().offset += colons.size();

    for(Chord ch : chordBuffer) // remove
    {
        qDebug() << ch.offset << ": " << ch.name;
    }

    if(colons.size() > 1)
    {
        // it's chords section

        Line line = {chordBuffer, ""};

        Section section = {ChordsLine, -1, {line}};
        sections_.push_back(section);

        currentSection = nullptr;

        chordBuffer.clear();
    }
}

void SongParser::parseNamedSectionLine_(QString& line, QList<SongParser::Chord>& chordBuffer, SongParser::Section*& currentSection)
{
    QRegExp lineExp("((Ref|Rec) (\\d+)\\. +)(.+)");
    if(! lineExp.exactMatch(line))
    {
        // TODO error
        return;
    }

    Section section;
    section.type = (lineExp.cap(2) == "Ref") ? Refrain : Recitation;
    section.number = lineExp.cap(3).toInt();

    sections_.push_back(section);
    currentSection = &sections_.back();

    line = lineExp.cap(4);
    parseLyricsLine_(line, chordBuffer, currentSection, lineExp.cap(1).size());
}

void SongParser::parseNumberedSectionLine_(QString& line, QList<SongParser::Chord>& chordBuffer, SongParser::Section*& currentSection)
{
    QRegExp lineExp("((\\d+)\\. +)(.+)");
    if(! lineExp.exactMatch(line))
    {
        // TODO error
        return;
    }

    Section section;
    section.type = Verse;
    section.number = lineExp.cap(2).toInt();

    sections_.push_back(section);
    currentSection = &sections_.back();

    line = lineExp.cap(3);
    parseLyricsLine_(line, chordBuffer, currentSection, lineExp.cap(1).size());
}

void SongParser::parseStarSectionLine_(QString& line, QList<SongParser::Chord>& chordBuffer, SongParser::Section*& currentSection)
{
    QRegExp lineExp("((\\*+)\\. +)(.+)");
    if(! lineExp.exactMatch(line))
    {
        // TODO error
        return;
    }

    Section section;
    section.type = Star;
    section.number = lineExp.cap(2).size();

    sections_.push_back(section);
    currentSection = &sections_.back();

    line = lineExp.cap(3);
    parseLyricsLine_(line, chordBuffer, currentSection, lineExp.cap(1).size());
}

void SongParser::parseUnmarkedSectionLine_(QString& line, QList<SongParser::Chord>& chordBuffer, SongParser::Section*& currentSection)
{
    QRegExp lineExp("(\\. +)(.+)");
    if(! lineExp.exactMatch(line))
    {
        // TODO error
        return;
    }

    Section section;
    section.type = Unmarked;
    section.number = -1;

    sections_.push_back(section);
    currentSection = &sections_.back();

    line = lineExp.cap(2);
    parseLyricsLine_(line, chordBuffer, currentSection, lineExp.cap(1).size());
}
