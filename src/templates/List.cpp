#pragma once
#include "Iterable.cpp"

template <typename list_element>
class List : public Iterable<list_element>
{
protected:
    list_element firstElement;
    unsigned int numOfElements = 0;
    
    list_element setFirstElement(list_element newElement)
    {   
        this->firstElement = newElement;
        return this->firstElement;
    }

public:
    List()
    {
        this->firstElement = nullptr;
        this->numOfElements = 0;
    }

    bool isEmpty() { return this->firstElement == nullptr; }

    /* Iterator returns each list element as long as there is nothing left */
    virtual Iterator<list_element>* getIterator() override
    {
        class Iter: public Iterator<list_element>
        {
            protected:
                list_element currentElement;
            public: 
                Iter(list_element firstElem) { this->currentElement = firstElem; }
                list_element next() override
                {   this->currentElement = this->currentElement->getNext();
                    return this->currentElement;
                }
                bool hasNext() override { return this->currentElement->getNext() != nullptr; }
        };
        return new Iter(this->firstElement);
    };

    /* Should be invoked whenever new item is added to list */
    virtual list_element onAddElement(list_element addedElement)
    {
        this->numOfElements++;
        return addedElement;
    }

    /* Adds element at the end of the list */
    virtual list_element addElement(list_element newElem)
    {
        if(this->firstElement == nullptr)
        {
            this->setFirstElement(newElem);
            return this->onAddElement(newElem);
        }

        list_element iterator = this->firstElement;
        while(iterator->getNext() != nullptr)
        {
            iterator = iterator->getNext();
        }

        iterator->setNextTo(newElem);
        newElem->setPreviousTo(iterator);

        return onAddElement(newElem);
    };

    /* Should be invoked whenever item is removed from list */
    virtual void onRemoveElement(list_element elemToRemove) { 
        delete elemToRemove;
        this->numOfElements--; 
    }

    /* Removes element from list by its unique id */
    virtual void deleteElement(std::string elementId)
    {
        list_element currentElem = this->firstElement;

        if(currentElem == nullptr)
        {
            std::cout<<"List is empty";
            return;
        }

        while(currentElem != nullptr)
        {
            if(currentElem->getId() == elementId)
            {
                std::cout<<"[DELETE] : "; currentElem->getInfo();
                
                // Removing first element
                if(currentElem == this->firstElement)
                {   
                    this->setFirstElement(currentElem->getNext());
                    return onRemoveElement(currentElem);
                }
                // Removing last element
                else if (currentElem->getNext() == nullptr)
                {
                    list_element prevElem = currentElem->getPrevious();
                    prevElem->setNextTo(nullptr);
                    return onRemoveElement(currentElem);
                }
                else 
                {
                    list_element prevElem = currentElem->getPrevious();
                    list_element nextElem = currentElem->getNext();
                    prevElem->setNextTo(nextElem);
                    nextElem->setPreviousTo(prevElem);
                    return onRemoveElement(currentElem);
                }
            }
            currentElem = currentElem->getNext();
        }

        return;
    };
    
    /* Displays all list elements */
    virtual void showElements()
    {
        list_element iterator = this->firstElement;
        
        if(iterator == nullptr)
        {
            std::cout<<"List is empty"<<std::endl;
            return;
        }

        while(iterator != nullptr)
        {
            iterator->getInfo();
            iterator = iterator->getNext();
        }
    };

    /* Removes all elements from list */
    virtual void clear()
    {
        list_element iterator = this->firstElement;
        
        if(iterator == nullptr)
        {
            std::cout<<"List is empty"<<std::endl;
            return;
        }

        while(iterator != nullptr)
        {
            std::string id = iterator->getId();
            iterator = iterator->getNext();
            this->deleteElement(id);
        }
    };

    virtual unsigned int getAmount()
    {
        return this->numOfElements;
    } 
};