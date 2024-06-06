#include "src/CustomerManager.hpp"


CustomerManager::CustomerManager(Visualiser window, bool * stopFlag)
{
        for (int i=0; i<3; i++)
    {
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, window.heigth/2, window.width, stopFlag);
        newCustomer->setX(2*i);
        customers->emplace(newCustomer);
    }
}