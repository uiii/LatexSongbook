#ifndef SONGBOOKGENERATOR_H
#define SONGBOOKGENERATOR_H

#include "common.h"
#include "song.h"
#include "instrument.h"

class SongbookGenerator
{
public:
    SongbookGenerator();

    static void generate(SongList& songs, Instrument* instrument, bool generateIndex = true);
};

#endif // SONGBOOKGENERATOR_H
