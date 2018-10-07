// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 09:52:33 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 09:52:34 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "../includes/rush00.hpp"

WINDOW		*create_win(void)
{
    int		max_y;
    int		max_x;
    WINDOW	*win;

    max_y = 52;
    max_x = 82;
   // getmaxyx(stdscr, max_y, max_x);
    win = newwin(max_y, max_x, 1, 1);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    return (win);
}

WINDOW    *startNcurse()
{
    WINDOW *win;

    initscr();
    win = create_win();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    return win;
}

void    forBackground(WINDOW *win)
{
    int x = 0;
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLUE);

    while (++x <= 80 )
        mvwprintw(win, 4, x, "-");
    wattron(win, A_STANDOUT | COLOR_PAIR(1));
    for (int y = 5; y <= 50; y++)
        for (x = 1; x <= 80; x++)
            mvwprintw(win, y, x, " ");
    wattroff(win, A_STANDOUT | COLOR_PAIR(1));

}

void    makeStars(WINDOW *win)
{
    static int arr[8][2] = {{34, 10}, {10, 15}, {25, 25}, {10, 35}, {6, 45}, {13, 55}, {45, 62}, {20, 78}};
    int len = -1;
    wattron(win, COLOR_PAIR(2) | A_BOLD);
    while (++len < 8) {
        if (arr[len][0] == 50) {
            arr[len][0] = 5;
        } else
            arr[len][0]++;

        mvwprintw(win, arr[len][0], arr[len][1], "*");
    }
    wattroff(win, COLOR_PAIR(2) | A_BOLD);
}

void    fireBullet(SpaceShip *ship)
{
    int i = -1;
    BulletClass* bullArr = ship->getBullets();

    while (++i < 40)
        if (bullArr[i].getPosY() == -1 && bullArr[i].getPosY() == -1) {
            bullArr[i].changePosYbull(ship->getPosY());
            bullArr[i].changePosXbull(ship->getPosX() + 3);
            return ;
        }
}

void    mySpaceship(WINDOW *win, SpaceShip *ship)
{

    char c = getch();
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(win, ship->getPosY(), ship->getPosX(), "||<O>||");
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    if (c == 'a')
    {
        if (ship->getPosX() > 1)
            ship->changePosX(ship->getPosX() - 1);
    }
    else if (c == 'd')
    {
        if (ship->getPosX() < 74)
            ship->changePosX(ship->getPosX() + 1);
    }
    else if (c == 'w')
    {
        if (ship->getPosY() > 5)
            ship->changePosY(ship->getPosY() - 1);
    }
    else if (c == 's')
    {
        if (ship->getPosY() < 50)
            ship->changePosY(ship->getPosY() + 1);
    }
    else if (c == ' ')
        fireBullet(ship);
    mvwprintw(win, 1, 1, "X ship:%d", ship->getPosX());
    mvwprintw(win, 2, 1, "Y ship:%d", ship->getPosY());
}

void    bulletCyclePosition(WINDOW *win, BulletClass* bullArr)
{
    int i = -1;
    while (++i < 40)
    {
        if (bullArr[i].getPosY() < 6)
        {
            bullArr[i].changePosYbull(-1);
            bullArr[i].changePosXbull(-1);
        }
        else
            bullArr[i].changePosYbull(bullArr[i].getPosY() - 1);
    }
    i = -1;
    while (++i < 40)
    {
        wattron(win, COLOR_PAIR(4) | A_BOLD);
        mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "o");
        wattroff(win, COLOR_PAIR(4) | A_BOLD);
    }
}

void    cycleGame(WINDOW *win, SpaceShip *ship)
{
    unsigned int i = 0;
    BulletClass* bullArr;
    time_t end,start;
    while (1)
    {
        time(&start);
        bullArr = ship->getBullets();
        if (i % 4 == 0) {
            forBackground(win);
            makeStars(win);
        }
        if (i % 2 == 0)
            bulletCyclePosition(win, bullArr);
        mySpaceship(win, ship);
        time(&end);
        usleep(10000 - 1000 * difftime(end, start));
        i++;
        wrefresh(win);
    }
}


int main() //x 1-80 y 1-50
{
    WINDOW *win;
    win = startNcurse();
    SpaceShip *ship = new SpaceShip();
    MyGame *game = new MyGame(win);
    game->addShip(ship);
    cycleGame(win, game->getShip());

    return 0;
}

