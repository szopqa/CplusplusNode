template <typename list_element>
class List
{
protected:
    list_element* firstElement;
    unsigned int numOfElements = 0;
    
    virtual list_element* onAddElement(list_element* addedElement)
    {
        this->numOfElements++;
        return addedElement;
    }

    virtual void onRemoveElement()
    {
        this->numOfElements--;
    }

public:
    List()
    {
        this->firstElement = nullptr;
        this->numOfElements = 0;
    }

    virtual list_element* addElement(list_element* newElem)
    {
        if(this->firstElement == nullptr)
        {
            this->firstElement = newElem;
            return this->onAddElement(newElem);
        }

        list_element* iterator = this->firstElement;
        while(iterator->getNext() != nullptr)
        {
            iterator = iterator->getNext();
        }

        iterator->setNextTo(newElem);
        newElem->setPreviousTo(iterator);

        return onAddElement(newElem);
    };

    virtual void deleteElement(std::string elementId)
    {
        list_element* iterator = this->firstElement;

        if(iterator == nullptr)
        {
            std::cout<<"List is empty";
            return;
        }

        while(iterator != nullptr)
        {
            if(iterator->getId() == elementId)
            {
                std::cout<<"[DELETE] : "; iterator->getInfo();
                // TODO: delete element from list
            }
            iterator = iterator->getNext();
        }

        return onRemoveElement();
    };
    
    virtual void showElements()
    {
        list_element* iterator = this->firstElement;
        
        if(iterator == nullptr)
        {
            std::cout<<"List is empty";
            return;
        }

        while(iterator != nullptr)
        {
            iterator->getInfo();
            iterator = iterator->getNext();
        }
    };

    virtual void clear()
    {
        list_element* iterator = this->firstElement;
        
        if(iterator == nullptr)
        {
            std::cout<<"List is empty";
            return;
        }

        while(iterator != nullptr)
        {
            std::string id = iterator->getId();
            this->deleteElement(id);
            iterator = iterator->getNext();
        }
    };

    virtual unsigned int getAmount()
    {
        return this->numOfElements;
    } 
};