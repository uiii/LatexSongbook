#ifndef COMMON_H
#define COMMON_H

#include <ctime>
#include "song.h"
#include "instrument.h"

typedef QList<std::time_t> EventList;
typedef QList<Song*> SongList;
typedef QList<Instrument*> InstrumentList;

#endif // COMMON_H
