//
// Created by login on 28.04.24.
//

#ifndef VISUALISER_H
#define VISUALISER_H
#include <src/Customer.h>
#include "src/Distributor.h"
#include "src/CustomersManager.h"
#include <iostream>
#include <memory>
#include <vector>


class Visualiser {
public:
    Visualiser() = default;
    ~Visualiser();
    int init();
    static void run(std::shared_ptr<CustomersManager> customersPtr, Distributor * distributor, bool& stopFlag, int width);
    int heigth = 0;
    int width;

};



#endif //VISUALISER_H
