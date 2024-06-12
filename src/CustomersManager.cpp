#include "CustomersManager.h"


CustomersManager::CustomersManager(int width, int heigth,  bool * stopFlag, std::shared_ptr<Distributor> distributor)
{
        for (int i=0; i<3; i++)
    {
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, heigth/2, width, stopFlag, distributor);
        newCustomer->setX(2*i);
        customers->emplace(newCustomer);
    }
    this->distributor = distributor;
    scrWidth = width;
    scrHeigth = heigth;
    stopFlagPtr = stopFlag;
    threadPointer = new std::thread(&CustomersManager::checkCustomersToRemove, this);

}

void CustomersManager::addCustomer(std::shared_ptr<Customer> customer){
    std::lock_guard<std::mutex> lock(mtx);
    customers->emplace(customer);
}

void CustomersManager::removeCustomer(std::shared_ptr<Customer> customer){
    std::lock_guard<std::mutex> lock(mtx);
    customers->erase(customer);
}

void CustomersManager::checkCustomersToRemove(){
    while (*stopFlagPtr!=true)
    {
    for(auto customer : *customers)
        {
            if (customer->toRemove)
            {
                removeCustomer(customer);
            }
        }
    }
    
}

CustomersManager::~CustomersManager(){
    threadPointer->join();
    delete threadPointer;
}