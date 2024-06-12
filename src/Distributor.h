#pragma once
#include <array>
#include <vector>
#include <thread>
#include <memory>
#include <unordered_set>
#include "CustomersManager.h"
#include "Customer.h"

struct Station{
    int xCorr;
    int yCorr;
    int id;
};

class Distributor{
    public:
    Distributor(int winwidth, int winheigth, std::shared_ptr<CustomersManager> customers, bool& stopFlag);
    ~Distributor();
    void checkCustomers(std::shared_ptr<CustomersManager> customersPtr);
    void switchStation();
    int xCorr;
    int yCorr;
    std::array<Station, 3> stations;
    Station currentStation;

    private:
    std::shared_ptr<CustomersManager> customersPtr;
    int width;
    int heigth;
    bool * stopFlagPtr;
    std::thread * threadPointer;
    std::thread * stationThreadPointer;

};
