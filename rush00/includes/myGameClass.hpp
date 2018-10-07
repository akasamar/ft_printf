// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   myGame.Class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 13:39:19 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 13:39:19 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MYGAMECLASS_HPP
#define MYGAMECLASS_HPP

#include <string>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "SpaceShipClass.hpp"

class MyGame
{
public:
    MyGame();
    MyGame(WINDOW *win);
    ~MyGame();

    void    addWindow(WINDOW *win);
    WINDOW    *getWindow(WINDOW *win);

    void    addShip(SpaceShip *ship);
    SpaceShip *getShip();

private:
    WINDOW* _win;
    SpaceShip *ship;
};

#endif