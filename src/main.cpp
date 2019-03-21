#include <iostream>
#include <string>
#include "./models/Worker.cpp"
#include "./lists/WorkersList.cpp"

int main(){
    WorkersList* workersList = new WorkersList();
    Worker* w1 = new Worker("Name1", "Surname1", 12);    
    Worker* w2 = new Worker("Name2", "Surname2", 32);        
    Worker* w3 = new Worker("Name3", "Surname3", 36);        

    workersList->addElement(w1);
    workersList->addElement(w2);
    workersList->addElement(w3);

    std::cout << workersList->getAmount()<<std::endl;
    workersList->showElements();

    workersList->deleteElement(w2->getId());
    workersList->deleteElement(w3->getId());
    std::cout << workersList->getAmount()<<std::endl;
    workersList->showElements();

    workersList->clear();
    std::cout << workersList->getAmount()<<std::endl;
    workersList->showElements();

    return 0;
}