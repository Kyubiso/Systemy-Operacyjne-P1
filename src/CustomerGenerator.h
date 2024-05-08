//
// Created by login on 06.05.24.
//

#ifndef CUSTOMERGENERATOR_H
#define CUSTOMERGENERATOR_H
#include <memory>
#include <vector>

#include "Customer.h"


class CustomerGenerator {
public:
    CustomerGenerator() = default;
    ~CustomerGenerator() = default;
   static int run(std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr, int winwidth, int winheigth);
private:
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customers;
};



#endif //CUSTOMERGENERATOR_H
