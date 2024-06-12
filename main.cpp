#include <iostream>
#include <memory>
#include "src/Customer.h"
#include "src/CustomerGenerator.h"
#include "src/Distributor.h"
#include "src/Visualiser.h"
#include "src/CustomersManager.h"
#include <ncurses.h>
#include <thread>
#include <vector>
#include <unordered_set>

namespace std {
    template <>
    struct hash<Customer> {
        size_t operator()(const Customer& c) const {
            return c.hash();
        }
    };
}

int main() {
    Visualiser window;
    CustomerGenerator customerGenerator;
    bool stopFlag;
    bool * flagPtr = &stopFlag;
    window.init();
    auto customers = std::make_shared<CustomersManager>(window.width, window.heigth, flagPtr);
    Distributor distributor(window.width, window.heigth, customers, stopFlag);

    for (int i=0; i<3; i++)
    {
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, window.heigth/2, window.width, flagPtr);
        newCustomer->setX(2*i);
        customers->addCustomer(newCustomer);
    }
    
    std::thread worker1(&CustomerGenerator::run, &customerGenerator, customers, window.width, window.heigth, std::ref(stopFlag));
    window.run(customers, &distributor, stopFlag, window.width);
    worker1.join();
}
