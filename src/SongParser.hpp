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
        Label,
        Unmarked,
        ChordsLine
    };

    struct Section
    {
        SectionType type;
        QString detail;

        QList<Line> lines;
    };

    struct Message
    {
        int line;
        QString text;
    };

    SongParser();

    void parse(const QString& text);

    bool noErrors() const;

    QString name() const;
    QString author() const;

    QList<Section> sections() const;
    QList<Message> errors() const;
    QList<Message> warnings() const;

private:
    void clear_();

    void parseText_() const;

    void newSection_(const QString& sectionLabel, Section*& currentSection) const;
    void newChordSection_(QList<Chord>& chordBuffer, Section*& currentSection) const;

    void parseLyricsLine_(const QString& line, int lineNumber, QList<Chord>& chordBuffer, Section*& currentSection, int offset = 0) const;
    void parseChordLine_(const QString& line, int lineNumber, QList<Chord>& chordBuffer, Section*& currentSection, int offset) const;

    QString name_;
    QString author_;
    QString text_;

    mutable bool parsed_;

    mutable QList<Section> sections_;
    mutable QList<Message> errors_;
    mutable QList<Message> warnings_;

    QString originalText_;
};

#endif // SONGPARSER_HPP
