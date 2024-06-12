#pragma once
#include <array>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <unordered_set>


struct Station{
    int xCorr;
    int yCorr;
    int id;
};

class Distributor{
    public:
    Distributor(int winwidth, int winheigth, bool& stopFlag);
    ~Distributor();
    int scheduleCustomer();
    std::mutex scheduleMutex;
    std::mutex firstDistMutex;
    std::mutex secondDistMutex;
    std::mutex thirdDistMutex;
    bool askStationifFree(int stationID);
    void lockStation(int stationID);
    void switchStation();
    int xCorr;
    int yCorr;
    std::array<Station, 3> stations;
    Station currentStation; 

    private:
    int width;
    int heigth;
    bool * stopFlagPtr;
    std::thread * stationThreadPointer;

};
