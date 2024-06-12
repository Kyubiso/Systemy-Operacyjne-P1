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
    auto distributor = std::make_shared<Distributor>(window.width, window.heigth, stopFlag);
    auto customers = std::make_shared<CustomersManager>(window.width, window.heigth, flagPtr, distributor);
    std::thread worker1(&CustomerGenerator::run, &customerGenerator, customers, window.width, window.heigth, std::ref(stopFlag), distributor);
    window.run(customers, distributor, stopFlag, window.width);
    worker1.join();
}
