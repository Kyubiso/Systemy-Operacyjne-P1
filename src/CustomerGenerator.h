//
// Created by login on 06.05.24.
//

#ifndef CUSTOMERGENERATOR_H
#define CUSTOMERGENERATOR_H
#include <memory>
#include <vector>
#include <unordered_set>

#include "Customer.h"
#include "CustomersManager.h"
#include "Distributor.h"



class CustomerGenerator {
public:
    CustomerGenerator() = default;
    ~CustomerGenerator() = default;
   void run(std::shared_ptr<CustomersManager> customersPtr, int winwidth, int winheigth, bool& stopFlag,  std::shared_ptr<Distributor> distributor);
private:
    std::shared_ptr<std::unordered_set<std::shared_ptr<Customer>>> customers;
};



#endif //CUSTOMERGENERATOR_H
