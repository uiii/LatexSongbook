#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <QString>

#include "SongParser.hpp"

class Generator
{
public:
    Generator();

    void generateSong(SongParser& parser);

private:
    QString generateLyrics_(SongParser::Section& section);
};

#endif // GENERATOR_HPP
