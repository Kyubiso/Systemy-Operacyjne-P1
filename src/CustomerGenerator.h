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
   void run(std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr, int winwidth, int winheigth, bool& stopFlag);
private:
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customers;
};



#endif //CUSTOMERGENERATOR_H
