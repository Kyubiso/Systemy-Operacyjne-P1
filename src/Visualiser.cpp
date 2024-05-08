//
// Created by login on 28.04.24.
//

#include "Visualiser.h"

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
    if (has_colors() == FALSE)
    {
        printw("Konsola nie obsluguje kolorow");
        return 0;
    }
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    attron(A_BOLD);
    mvprintw(heigth/2, (width/2) - (sizeof(txt)/2), txt);
    attroff(COLOR_PAIR(1));
    getch();
    nodelay(stdscr, TRUE);
    clear();
    return 0;
}
int Visualiser::run(std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customersPtr, int winwidth, int winheigth)
{
    clear();
    if (!customersPtr) printw("Błąd wskaźnika klientów");
    int ch;

        if(customersPtr->front()->getX()>winwidth)
        {
            customersPtr->erase(customersPtr->begin());
        }
        refresh();
        const auto& customers = *customersPtr;
        for(const auto& customer : customers)
        {
            mvprintw(customer->getY(), customer->getX(), customer->getAscii());
            customer->move(1,0);
            getch();
        }
        usleep(1000000);
        clear();
    move(9,0);
    printw("Koniec programu, wcisnij dowolny przycisk...");
    getch();
    endwin();
    return 0;
}

int Visualiser::close()
{
    endwin();
    return 0;
}



