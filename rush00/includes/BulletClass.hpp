// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BulletClass.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 13:50:18 by akasamar          #+#    #+#             //
//   Updated: 2018/10/07 13:50:19 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLETCLASS_HPP
#define BULLETCLASS_HPP

#include <string>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>

class BulletClass
{
public:
    BulletClass();
    BulletClass(int y, int x);
    ~BulletClass();

    void    changePosXbull(int x);
    void   changePosYbull(int y);

    int     getPosX();
    int    getPosY();

private:
    int _y;
    int _x;
};

#endif