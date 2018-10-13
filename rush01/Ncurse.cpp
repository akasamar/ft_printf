// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 14:47:20 by akasamar          #+#    #+#             //
//   Updated: 2018/10/13 14:47:21 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurse.hpp"


Ncurse::Ncurse(){
    FirstArray = new int[100];
    SecondArray = new int[99];
    for (int i = 0; i < 100; i++) {
        FirstArray[i] = 0;
        if (i < 99)
            SecondArray[i] = 0;
    }
    start_ncurse_mode();
}

Ncurse::Ncurse(Ncurse const & src) {

    *this = src;
}

Ncurse & Ncurse::operator=(Ncurse const & src) {
    this->_win1 = src._win1;
    this->_win2 = src._win2;
    this->_win3 = src._win3;
    this->_win4 = src._win4;
    this->FirstArray = src.FirstArray;
    this->SecondArray = src.SecondArray;
    return (*this);
}

Ncurse::~Ncurse(){
    delete [] FirstArray;
    delete [] SecondArray;
}

void    Ncurse::setWin1(WINDOW *win1)
{
    _win1 = win1;
}
void    Ncurse::setWin2(WINDOW *win2)
{
    _win2 = win2;
}

void    Ncurse::setWin3(WINDOW *win3)
{
    _win3 = win3;
}

void    Ncurse::setWin4(WINDOW *win4)
{
    _win4 = win4;
}

WINDOW*    Ncurse::getWin1()
{
    return _win1;
}
WINDOW*    Ncurse::getWin2()
{
    return _win2;
}

WINDOW*    Ncurse::getWin3()
{
    return _win3;
}

WINDOW*    Ncurse::getWin4()
{
    return _win4;
}

void       Ncurse::inputDiagram(WINDOW *getWin, int data) {
    int k = 0;
    FirstArray[0] = data;
    for (k = 0; k < 99; k++)
        FirstArray[k + 1] = SecondArray[k];
    int z = 0;
    int i = 0;
        while (z < 5) {
            while (i < 100) {
                if (FirstArray[i] > 80 && z == 0) {
                    wattron(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(1) | A_STANDOUT);
                }
                else if (FirstArray[i] > 60 && z == 1) {
                    wattron(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(1) | A_STANDOUT);
                }
                else if (FirstArray[i] > 40 && z == 2) {
                    wattron(getWin,COLOR_PAIR(2) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(2) | A_STANDOUT);
                }
                else if (FirstArray[i] > 20 && z == 3) {
                    wattron(getWin,COLOR_PAIR(2) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(2) | A_STANDOUT);
                }
                else if (FirstArray[i] > 0 && z == 4) {
                    wattron(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(3) | A_STANDOUT);
                }
                else
                {
                    wattron(getWin,COLOR_PAIR(4) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(4) | A_STANDOUT);
                }
                i++;
            }
            z++;
            i = 0;
        }
        for (k = 0; k < 99; k++)
            SecondArray[k] = FirstArray[k];
}

void    Ncurse::checkSizeWindow()
{
    int y, x;
    getmaxyx(stdscr,y,x);
    if (y < 72 || x < 243)
    {
        endwin();
        std::cout << "Too little terminal window for starting this programm." << std::endl;
        exit(0);
    }
}

void    Ncurse::create_win()
{

    const int     max_y = 10;
    const int     max_x = 110;

    setWin1(newwin(max_y, max_x, 15, 1));
    setWin2(newwin(max_y, max_x, 30, 1));
    setWin3(newwin(max_y, max_x, 45, 1));
    setWin4(newwin(70, 120, 1, 120));
    box(getWin1(), 0, 0);
    box(getWin2(), 0, 0);
    box(getWin3(), 0, 0);
    box(getWin4(), 0, 0);
    refresh();
    wrefresh(getWin1());
    wrefresh(getWin2());
    wrefresh(getWin3());
    wrefresh(getWin4());
}

void Ncurse::start_ncurse_mode()
{
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();

    checkSizeWindow();

    create_win();

    mvwprintw(getWin1(), 1, 1, "CPU");
    mvwprintw(getWin2(), 1, 1, "RAM");
    mvwprintw(getWin3(), 1, 1, "NETWORK");
    mvwprintw(getWin4(), 1, 1, "All processes");

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);

    wrefresh(getWin1());
    wrefresh(getWin2());
    wrefresh(getWin3());
    wrefresh(getWin4());


    int k = rand() % 100;

    while (1)
    {
        k = rand() % 100;
        inputDiagram(getWin1(), k);
//        inputDiagram(getWin2(), k);
//        inputDiagram(getWin3(), k);
        wrefresh(getWin1());
        wrefresh(getWin2());
        wrefresh(getWin3());
        wrefresh(getWin4());
        mvprintw(1, 1, STR1);
        refresh();
        usleep(80000);
    }

}