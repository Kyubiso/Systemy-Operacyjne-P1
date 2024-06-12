#ifndef CUSTOMERSMANAGER_H
#define CUSTOMERSMANAGER_H
#include <unordered_set>
#include <memory>
#include <mutex>
#include "Customer.h"
#include "Distributor.h"

class CustomersManager
{
public:
    std::mutex mtx;
    CustomersManager(int width, int heigth,  bool * stopFlag, std::shared_ptr<Distributor> distributor);
    ~CustomersManager();
    std::shared_ptr<std::unordered_set<std::shared_ptr<Customer>>> customers = std::make_shared<std::unordered_set<std::shared_ptr<Customer>>>();
    void addCustomer(std::shared_ptr<Customer> customer);
    void removeCustomer(std::shared_ptr<Customer> customer);

private:
    int scrWidth;
    int scrHeigth;
    bool * stopFlagPtr;
    std::shared_ptr<Distributor> distributor;
    void checkCustomersToRemove();
    std::thread * threadPointer;


};

#endif //CUSTOMERSMANAGER_H

