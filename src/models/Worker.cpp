#pragma once
#include <iostream>
#include <string>
#include "../templates/ListElement.cpp"

class Worker: public ListElement<Worker>
{
private:
    std::string name;
    std::string surname;
    int age;

public:
    Worker(std::string name, std::string surname, int age)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->previous = nullptr;
        this->next = nullptr;
    }

    void getInfo() override
    {
        std::cout << "[WORKER]: id: "<<this->id<<" name: "<<this->name<<" surname: "<<this->surname<<" age: "<<this->age<<std::endl;
    }
};
