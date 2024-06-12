#include "Distributor.h"


Distributor::Distributor(int winwidth, int winheigth, bool& stopFlag){

    width = winwidth;
    heigth = winheigth;

    xCorr = 35; //Main distributor x
    yCorr = winheigth/2;
    stopFlagPtr = &stopFlag;
    stations[0].yCorr = winheigth/3;
    stations[1].yCorr = winheigth/2;
    stations[2].yCorr = 2*winheigth/3;

    stations[0].xCorr = 3*width/4;
    stations[1].xCorr = 3*width/4;
    stations[2].xCorr = 3*width/4;

    stations[0].id = 0;
    stations[1].id = 1;
    stations[2].id = 2;

    // customersPtr = customers;
   // threadPointer = new std::thread(&Distributor::checkCustomers, this, customersPtr);
    stationThreadPointer = new std::thread(&Distributor::switchStation, this);

}

int Distributor::scheduleCustomer(){
     std::lock_guard<std::mutex> lock(scheduleMutex);
     return currentStation.yCorr;
}

void Distributor::switchStation(){
    int i = 0;
    while (*stopFlagPtr!=true)
    {
        scheduleMutex.lock();
        if (i==2) {
            i=0;
        }
       else{
            i++;
       }
        currentStation = stations[i];
        scheduleMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}

bool Distributor::askStationifFree(int stationID){
    std::lock_guard<std::mutex> lock(scheduleMutex);
    bool permission = 0;
    switch(stationID){
        case 1:
             if(firstDistMutex.try_lock()){
                permission=1;
                firstDistMutex.unlock();
             }
             
            break;
        case 2:
            if(secondDistMutex.try_lock()){
                permission=1;
                secondDistMutex.unlock();
             }
            break;
        case 3:
            if(thirdDistMutex.try_lock()){
                permission=1;
                thirdDistMutex.unlock();
             }
            break;
        default:
            break;
    }

    return permission;
}

void Distributor::lockStation(int stationID){
    switch(stationID){
        case 1:{
            std::lock_guard<std::mutex> lock(firstDistMutex);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;
        }
        case 2:
        {
            std::lock_guard<std::mutex> lock(secondDistMutex);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;}
        case 3:
        {
            std::lock_guard<std::mutex> lock(thirdDistMutex);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;
        }
        default:
            break;
    }
}

Distributor::~Distributor(){
    stationThreadPointer->join();
    delete stationThreadPointer;
}