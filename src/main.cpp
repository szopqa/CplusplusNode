#include <iostream>
#include <string>
#include "./models/Worker.cpp"
#include "./lists/WorkersList.cpp"

int main(){
    WorkersList workersList = WorkersList();
    Worker* w = new Worker("Name1", "Surname1", 12);    
    Worker* w2 = new Worker("Name2", "Surname2", 41);    
    workersList.addElement(w);
    workersList.addElement(w2);

    std::cout << workersList.getAmount()<<std::endl;
    workersList.showElements();
    workersList.clear();

    return 0;
}