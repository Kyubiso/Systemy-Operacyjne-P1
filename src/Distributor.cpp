#include "Distributor.h"


Distributor::Distributor(int winwidth, int winheigth, std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customers, bool& stopFlag){

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

    customersPtr = customers;
    threadPointer = new std::thread(&Distributor::checkCustomers, this, customersPtr);
    stationThreadPointer = new std::thread(&Distributor::switchStation, this);

}

void Distributor::checkCustomers(std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr){
    while (*stopFlagPtr!=true)
    {
    for(auto customer : *customersPtr)
        {
            if(customer->getX() == xCorr){
                customer->setY(currentStation.yCorr);
            }

            if(customer->getX() == 3*width/4){
                customer->setWaitFlag();
            }
        }
    }
    
}

void Distributor::switchStation(){
    int i = 0;
    while (*stopFlagPtr!=true)
    {
        if (i==2) {
            i=0;
        }
       else{
            i++;
       }
        currentStation = stations[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}

Distributor::~Distributor(){
    threadPointer->join();
    delete threadPointer;
    stationThreadPointer->join();
    delete stationThreadPointer;
}