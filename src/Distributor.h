#pragma once
#include <array>
#include <algorithm>
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
    void changeStationOccupancy(int stationID, int value);
    std::mutex scheduleMutex;
    std::mutex firstDistMutex;
    std::mutex secondDistMutex;
    std::mutex thirdDistMutex;
    std::mutex occupancyMutex;
    bool askStationifFree(int stationID);
    void lockStation(int stationID);
    void switchStation();
    int xCorr;
    int yCorr;
    int maxIndex;
    std::array<Station, 3> stations;
    Station currentStation; 

    int occupancyArray[3] = {0, 0, 0};
    private:
    int width;
    int heigth;
    bool * stopFlagPtr;
    std::thread * stationThreadPointer;
    int findMaxIndex();

};
