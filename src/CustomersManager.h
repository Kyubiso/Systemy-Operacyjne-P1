#ifndef CUSTOMERSMANAGER_H
#define CUSTOMERSMANAGER_H
#include <unordered_set>
#include <memory>
#include <mutex>
#include "Customer.h"

class CustomersManager
{
public:
    std::mutex mtx;
    CustomersManager(int width, int heigth,  bool * stopFlag);
    ~CustomersManager() = default;
    std::shared_ptr<std::unordered_set<std::shared_ptr<Customer>>> customers = std::make_shared<std::unordered_set<std::shared_ptr<Customer>>>();
    void addCustomer(std::shared_ptr<Customer> customer);
    void removeCustomer(std::shared_ptr<Customer> customer);

};

#endif //CUSTOMERSMANAGER_H

