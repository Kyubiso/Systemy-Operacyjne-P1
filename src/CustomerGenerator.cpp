//
// Created by login on 06.05.24.
//

#include "CustomerGenerator.h"

#include <chrono>
#include <random>
#include <thread>
#include <utility>
#include <unordered_set>

void CustomerGenerator::run(std::shared_ptr<CustomersManager> customersPtr, int winwidth, int winheigth, bool& stopFlag,  std::shared_ptr<Distributor> distributor)
{
    while(stopFlag!=true)
    {
        bool * reference = &stopFlag;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 5000);
        int delay = dis(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, winheigth/2, winwidth, reference, distributor);
        customersPtr->addCustomer(newCustomer);
    }
}


