//
// Created by login on 19.04.24.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H



class Customer {
public:
    Customer(float x_, float y_);
    float getX() const;
    float getY() const;

private:
    float x,y;
};



#endif //CUSTOMER_H
