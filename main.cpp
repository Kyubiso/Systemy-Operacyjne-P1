#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>
#include <src/Visualiser.h>
#include <src/Customer.h>
#include <ncurses.h>
#include <thread>
#include <vector>

#include "src/CustomerGenerator.h"

int main() {
    Visualiser window;
    window.init();
    auto customers = std::make_shared<std::vector<std::shared_ptr<Customer>>>();
    for (int i=0; i<3; i++)
    {
        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(0, window.heigth/2);
        newCustomer->setX(2*i);
        customers->push_back(newCustomer);
    }
    int ch;
    while ((ch = getch())!='x')
    {
        std::thread worker1(CustomerGenerator::run, customers, window.width, window.heigth); //TODO zrób ten wątek
        std::thread worker2(Visualiser::run, customers, window.width, window.heigth);
        worker1.join();
        worker2.join();
    }
}
