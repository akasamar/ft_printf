// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceShip.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 13:37:25 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 13:37:26 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACESHIPCLASS_HPP
#define SPACESHIPCLASS_HPP

#include <string>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "BulletClass.hpp"

class SpaceShip
{
public:
    SpaceShip();
    ~SpaceShip();
    void    changePosX(int x);
    void    changePosY(int y);
    int    getPosX();
    int    getPosY();
    BulletClass* getBullets();
private:
    int _posX;
    int _posY;
    BulletClass *bullet;
};

#endif