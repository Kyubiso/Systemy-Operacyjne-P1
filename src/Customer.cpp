//
// Created by login on 19.04.24.
//

#include "Customer.h"
#include "random"
#include <cstdlib>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

Customer::Customer(float x_, float y_, int width, bool * stopflag)
{
    x = x_;
    y = y_;
    winwidth = width;
    std::random_device rd;  // Inicjalizacja generatora liczb losowych
    std::mt19937 gen(rd()); // Ustawienie generatora na generator Mersenne Twister
    std::uniform_int_distribution<int> distribution(65, 90 ); // ZNaki od A do Z
    std::uniform_int_distribution<int> speedDistribution(100, 400); // Dystrybucja predkosci
    stopFlagPtr = stopflag;
    symbol = (char)distribution(gen);
    speed = speedDistribution(gen);
    threadPointer = new std::thread(&Customer::updateLocation, this);
}

Customer::~Customer(){
    threadPointer->join();
    delete threadPointer;
}
int Customer::getX() const {
    return x;
}

int Customer::getY() const {
    return y;
}

void Customer::setX(int xpos)
{
    x=xpos;
}

void Customer::setY(int ypos)
{
    y=ypos;
}

void Customer::move(int x2, int y2)
{
    setX(x+x2);
    setY(y+y2);
}
void Customer::updateLocation()
{
while(*stopFlagPtr!=true)
{  
    if(waitFlag!=1){
        move(1,0);
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}    

}

char* Customer::getAscii()
{
    return &symbol;
}

void Customer::setWaitFlag(){
    waitFlag = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    waitFlag = 0;
}

 void Customer::generateGUID() {
        id = boost::uuids::random_generator()();
    }

std::string Customer::getIDAsString() const {
    return boost::uuids::to_string(id);
    }

