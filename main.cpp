#include <iostream>
#include <memory>
#include "src/Customer.h"
#include "src/CustomerGenerator.h"
#include "src/Distributor.h"
#include "src/Visualiser.h"
#include "src/CustomersManager.h"
#include <ncurses.h>
#include <thread>
#include <vector>
#include <unordered_set>
/*Projekt z przedmiotu Systemy Operacyjne 2
Zadanie: Zaprojektować symulacje systemu kolejek w którym klienci poruszają się w strone stacji i są rozdzielani
na jedną  trzech stacji przed Dystrybutor. Klienci poruszają się niezależnie z losowymi prędkościami i zatrzymują się
na chwilę na jednej z trzech stacji końcowych. 
Wymagania na Etap 2:
    -Tylko jeden klient może być obsługiwany na raz w jednej stacji
    -Najbardziej zajęta stacja ma być wyłączona z puli stacji, do których idą klienci*/

namespace std {
    template <>
    struct hash<Customer> {
        size_t operator()(const Customer& c) const {
            return c.hash();
        }
    };
}

int main() {
    Visualiser window;
    CustomerGenerator customerGenerator;
    bool stopFlag;
    bool * flagPtr = &stopFlag;
    window.init();
    auto distributor = std::make_shared<Distributor>(window.width, window.heigth, stopFlag);
    auto customers = std::make_shared<CustomersManager>(window.width, window.heigth, flagPtr, distributor);
    std::thread worker1(&CustomerGenerator::run, &customerGenerator, customers, window.width, window.heigth, std::ref(stopFlag), distributor);
    window.run(customers, distributor, stopFlag);
    worker1.join();
}
