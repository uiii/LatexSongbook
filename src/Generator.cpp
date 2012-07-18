#include "Generator.hpp"

#include <QDebug>

#include <string>

Generator::Generator()
{
}

void Generator::generateSong(SongParser& parser)
{
    QString latexOutput;

    QTextStream stream(&latexOutput);

    stream << "\\begin{song}{" << parser.name() << "}{" << parser.author() << "}\n";

    for(SongParser::Section section : parser.sections())
    {
        switch(section.type)
        {
            case SongParser::Verse:
                stream << "\t\\Verse {" << generateLyrics_(section) << "}\n";
            break;
            case SongParser::Refrain:
                stream << "\t\\Ref";
                if(! section.detail.isEmpty())
                {
                    stream << "[" << section.detail << "]";
                }
                stream << " {" << generateLyrics_(section) << "}\n";
            break;
            case SongParser::Recitation:
                stream << "\t\\Rec {" << generateLyrics_(section) << "}\n";
            break;
            case SongParser::Label:
                stream << "\t\\Label{$" << section.detail << "$} {" << generateLyrics_(section) << "}\n";
            break;
            default:
            break;
        }
    }

    stream << "\\end{song}";

    qDebug() << latexOutput;
}

QString Generator::generateLyrics_(SongParser::Section& section)
{
    QString lyrics;
    QTextStream out(&lyrics);

    bool firstLine = true;
    for(SongParser::Line line : section.lines)
    {
        if(firstLine)
        {
            firstLine = false;
        }
        else
        {
            out << "\\n\n\t";
        }

        QTextStream in(&line.lyrics);

        SongParser::Chords::Iterator chordIt;
        SongParser::Chords::Iterator nextChordIt;
        chordIt = line.chords.begin();

        if(chordIt == line.chords.end())
        {
            out << in.readAll();
        }
        else
        {
            out << in.read(chordIt->offset);
        }

        while(chordIt != line.chords.end())
        {
            out << "|" << chordIt->name << "|";

            nextChordIt = chordIt + 1;
            if(nextChordIt == line.chords.end())
            {
                out << in.readAll() << "|";
            }
            else
            {
                QString substr = in.read(nextChordIt->offset);
                out << substr << "|";
            }

            chordIt++;
        }
    }

    return lyrics;
}
