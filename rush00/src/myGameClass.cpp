// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   myGame.Class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 13:39:26 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 13:39:26 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/myGameClass.hpp"

MyGame::MyGame()
{
    return ;
}

MyGame::MyGame(WINDOW *win) : _win(win)
{
    return ;
}

MyGame::~MyGame()
{
    return ;
}

WINDOW    *MyGame::getWindow(WINDOW *win)
{
    return win;
}

void    MyGame::addShip(SpaceShip *ship)
{
    this->ship = ship;
}

SpaceShip *MyGame::getShip()
{
    return ship;
}