//
// Created by login on 28.04.24.
//

#include "Visualiser.h"
#include "CustomersManager.h"

#include <memory>

#include "ncurses.h"
#include "thread"
#include "chrono"
#include "unistd.h"

int Visualiser::init()
{
    char txt[]= "Let it go...";
    initscr();
    getmaxyx(stdscr, heigth, width);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    if (has_colors() == FALSE)
    {
        printw("Konsola nie obsluguje kolorow");
        return 0;
    }
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    attron(A_BOLD);
    mvprintw(heigth/2, (width/2) - (sizeof(txt)/2), "%s", txt);
    attroff(COLOR_PAIR(1));
    getch();
    nodelay(stdscr, TRUE);
    clear();
    return 0;
}
void Visualiser::run(std::shared_ptr<CustomersManager> customersPtr, std::shared_ptr<Distributor> distributor, bool& stopFlag, int width)
{
    char ch;
    while((ch = getch())!='x'){
        erase();
        init_pair(1, COLOR_BLACK, COLOR_RED);
        init_pair(2, COLOR_BLACK, COLOR_CYAN);
        init_pair(3, COLOR_BLACK, COLOR_GREEN);
        attron(COLOR_PAIR(1));
        mvprintw(distributor->yCorr, distributor->xCorr, " ");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        for(Station station : distributor->stations){
            if (station.id == distributor->currentStation.id)
            {
               attron(COLOR_PAIR(3));
               mvprintw(station.yCorr, station.xCorr, " ");
               attroff(COLOR_PAIR(3));
            }
            else{
                attron(COLOR_PAIR(2));
                mvprintw(station.yCorr, station.xCorr, " ");
                attroff(COLOR_PAIR(2));
            }
            
            
        }
        attroff(COLOR_PAIR(2));
        if (!customersPtr) printw("Błąd wskaźnika klientów");
        
        for(const auto& customer : *customersPtr->customers)
        {
            mvprintw(customer->getY(), customer->getX(), customer->getAscii());
        }
        //refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    stopFlag=1;
    echo();
    clear();
    mvprintw(0,0, "Koniec wykonywania programu...");
    getch();
}

Visualiser::~Visualiser(){
    endwin();
}


