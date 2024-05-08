//
// Created by login on 19.04.24.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<ncurses.h>



class Customer {
public:
    Customer(float x_, float y_);
    ~Customer() = default;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int x2, int y2);
    char* getAscii();

private:
    int x,y;
    //od 33 do 122
    char symbol;
};



#endif //CUSTOMER_H
