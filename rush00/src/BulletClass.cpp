// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BulletClass.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 13:50:14 by akasamar          #+#    #+#             //
//   Updated: 2018/10/07 13:50:14 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/BulletClass.hpp"

BulletClass::BulletClass ()
{
    _x = -1;
    _y = -1;
    return ;
}

BulletClass::BulletClass (int y, int x) : _y(-1), _x(-1)
{
    return ;
}

void    BulletClass::changePosXbull(int x)
{
    _x = x;
}
void    BulletClass::changePosYbull(int y){
    _y = y;
}

int    BulletClass::getPosX()
{
    return _x;
}
int    BulletClass::getPosY(){
    return _y;
}

BulletClass::~BulletClass ()
{
    return ;
}
