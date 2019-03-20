#pragma once

template <typename iter_element>
class Iterator
{
public:
    virtual iter_element next() = 0;
    virtual bool hasNext() = 0;
};