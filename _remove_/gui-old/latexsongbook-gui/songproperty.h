#ifndef SONGPROPERTY_H
#define SONGPROPERTY_H

#include <song.h>

template< typename Return >
class SongProperty
{
public:
    typedef Return (Song::*type)() const;
    typedef Return return_type;
};

#endif // SONGPROPERTY_H
