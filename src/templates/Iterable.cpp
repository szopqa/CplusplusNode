#pragma once
#include "Iterator.cpp"

template <typename T>
class Iterable
{
public:
    virtual Iterator<T>* getIterator() = 0;
};
