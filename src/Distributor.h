#pragma once
#include <array>
#include <vector>
#include <thread>
#include <memory>
#include "src/Customer.h"
struct Station{
    int xCorr;
    int yCorr;
    int id;
};

class Distributor{
    public:
    Distributor(int winwidth, int winheigth, std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customers, bool& stopFlag);
    ~Distributor();
    void checkCustomers(std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr);
    void switchStation();
    int xCorr;
    int yCorr;
    std::array<Station, 3> stations;
    Station currentStation;

    private:
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr;
    int width;
    int heigth;
    bool * stopFlagPtr;
    std::thread * threadPointer;
    std::thread * stationThreadPointer;

};
