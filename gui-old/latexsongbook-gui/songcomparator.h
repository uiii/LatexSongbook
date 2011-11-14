#ifndef SONGCOMPARATOR_H
#define SONGCOMPARATOR_H

#include <songproperty.h>
#include <iostream>

template< typename Property >
class SongComparator
{
public:

    SongComparator(Property property, Qt::SortOrder order):
        property_(property),
        order_(order)
    {}

    bool operator ()(Song* first, Song* second)
    {
        switch(order_)
        {
            case Qt::AscendingOrder:
                return ascCompare(first, second);
                break;
            case Qt::DescendingOrder:
                return descCompare(first, second);
                break;
            default:
                return ascCompare(first, second);
                break;
        }
    }

    bool ascCompare(Song* first, Song* second)
    {
        return lessThen((first->*property_)(), (second->*property_)());
    }

    bool descCompare(Song* first, Song* second)
    {
        return greaterThen((first->*property_)(), (second->*property_)());
    }

private:
    Property property_;
    Qt::SortOrder order_;

    bool lessThen(const QString& left, const QString& right)
    {
        return left.localeAwareCompare(right) < 0 ;
    }

    bool greaterThen(const QString& left, const QString& right)
    {
        return left.localeAwareCompare(right) > 0 ;
    }

    template< typename T >
    bool lessThen(const T& left, const T& right)
    {
        return left < right;
    }

    template< typename T >
    bool greaterThen(const T& left, const T& right)
    {
        return left > right;
    }
};

#endif // SONGCOMPARATOR_H
