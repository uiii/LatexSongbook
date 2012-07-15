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
};

#endif // GENERATOR_HPP
