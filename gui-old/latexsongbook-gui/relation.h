#ifndef RELATION_H
#define RELATION_H

template< typename Type >
class Relation
{
public:
    virtual bool operator()(const Type& left, const Type& right) const = 0;
};

template< typename Type >
class LessThen : public Relation<Type>
{
public:
    bool operator()(const Type& left, const Type& right) const
    {
        return left < right;
    }
};

template< typename Type >
class GreaterThen : public Relation<Type>
{
public:
    bool operator()(const Type& left, const Type& right) const
    {
        return left > right;
    }
};

template< typename Type >
class LessThenOrEqual : public Relation<Type>
{
public:
    bool operator()(const Type& left, const Type& right) const
    {
        return left <= right;
    }
};

template< typename Type >
class GreaterThenOrEqual : public Relation<Type>
{
public:
    bool operator()(const Type& left, const Type& right) const
    {
        return left >= right;
    }
};

template< typename Type >
class Equal : public Relation<Type>
{
public:
    bool operator()(const Type& left, const Type& right) const
    {
        return left == right;
    }
};

#endif // RELATION_H
