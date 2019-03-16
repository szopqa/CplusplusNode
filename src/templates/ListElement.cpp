#pragma once
#include "../utils/uuidGenerator.cpp"

template <typename T>
class ListElement
{
protected:
    T* next;
    T* previous;
    std::string id;
public:
    ListElement()
    {
        this->id = uuidGenerator().generateUuid();
    }

    virtual void getInfo() = 0;

    virtual T* getPrevious()
    {
        return this->previous;
    };

    virtual T* getNext()
    {
        return this->next;
    };

    virtual void setPreviousTo(T* prev)
    {
        this->previous = prev;
    };

    virtual void setNextTo(T* next)
    {
        this->next = next;
    };

    std::string getId()
    {
        return this->id;
    }
};
