//
// Created by login on 19.04.24.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<ncurses.h>
#include<thread>
#include<memory>
#include<mutex>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "Distributor.h"


class Customer {
public:
    Customer(float x_, float y_, int width, bool * stopFlag, std::shared_ptr<Distributor> distributor);
    ~Customer();
    boost::uuids::uuid id;
    bool * stopFlagPtr;
    bool toRemove;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setWaitFlag();
    void move(int x2, int y2);
    void moveTo(int x, int y);
    char* getAscii();
    void updateLocation();
    std::string getIDAsString() const;

     // Funkcja haszująca dla obiektów Customer
   std::size_t hash() const {
        return boost::uuids::hash_value(id);
    }

    // Operator równości dla porównywania obiektów Customer
    bool operator==(const Customer& other) const {
        return id == other.id;
    }

private:
    std::mutex moveMutex;
    std::shared_ptr<Distributor> distributor;
    bool waitFlag = 0;
    bool isChecked = 0;
    int x,y;
    char symbol;
    int speed;
    int winwidth;
    std::thread * threadPointer;
    void generateGUID();
    int stationID;
};



#endif //CUSTOMER_H
