#ifndef SONGFILTER_H
#define SONGFILTER_H

#include <songproperty.h>
#include <relation.h>

class SongFilter
{
public:
    virtual bool check(Song* song) const = 0;
};

template< typename Property, typename Relation >
class SongPropertyFilter : public SongFilter
{
public:
    SongPropertyFilter(typename Property::type property, typename Property::return_type value):
        property_(property),
        value_(value)
    {
    }

    inline bool check(Song* song) const
    {
        return Relation()((song->*property_)(), value_);
    }

private:
    typename Property::type property_;
    typename Property::return_type value_;
};

class NoFilter : public SongFilter
{
public:
    inline bool check(Song*) const
    {
        return true;
    }
};

#endif // SONGFILTER_H
