//
// Created by login on 19.04.24.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<ncurses.h>
#include<thread>



class Customer {
public:
    Customer(float x_, float y_, int width, bool * stopFlag);
    ~Customer();
    bool * stopFlagPtr;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int x2, int y2);
    char* getAscii();
    void updateLocation();

private:
    int x,y;
    //od 33 do 122
    char symbol;
    int speed;
    int winwidth;
    std::thread * threadPointer;
};



#endif //CUSTOMER_H
