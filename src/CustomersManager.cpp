#include "CustomersManager.h"


CustomersManager::CustomersManager(int width, int heigth,  bool * stopFlag)
{
        for (int i=0; i<3; i++)
    {
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, heigth/2, width/2, stopFlag);
        newCustomer->setX(2*i);
        customers->emplace(newCustomer);
    }
}

void CustomersManager::addCustomer(std::shared_ptr<Customer> customer){
    std::lock_guard<std::mutex> lock(mtx);
    customers->emplace(customer);
}

void CustomersManager::removeCustomer(std::shared_ptr<Customer> customer){
    std::lock_guard<std::mutex> lock(mtx);
    customers->erase(customer);
}