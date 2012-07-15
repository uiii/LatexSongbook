#ifndef SONGPARSER_HPP
#define SONGPARSER_HPP

#include <QString>
#include <QList>

class SongParser
{
public:
    struct Chord
    {
        int offset;
        QString name;
    };

    typedef QList<Chord> Chords;

    struct Line
    {
        Chords chords;
        QString lyrics;
    };

    enum SectionType
    {
        Verse,
        Refrain,
        Recitation,
        Star,
        Unmarked,
        ChordsLine
    };

    struct Section
    {
        SectionType type;
        int number;

        QList<Line> lines;
    };

    struct Error
    {
        int line;
        QString message;
    };

    SongParser(const QString& text);

    bool correct() const;

    QString name() const;
    QString author() const;

    QList<Section> sections();

private:
    void parseText_();

    void parseLyricsLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection, int offset = 0);
    void parseChordLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection);
    void parseNamedSectionLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection);
    void parseNumberedSectionLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection);
    void parseStarSectionLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection);
    void parseUnmarkedSectionLine_(QString& line, QList<Chord>& chordBuffer, Section*& currentSection);

    QString name_;
    QString author_;

    QList<Section> sections_;

    bool parsed_;

    QList<Error> errors_;

    QString originalText_;
};

#endif // SONGPARSER_HPP
