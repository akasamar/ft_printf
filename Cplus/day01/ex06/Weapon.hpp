// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:49:23 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:49:25 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
public:
    Weapon(std::string type);
    ~Weapon();
    std::string getType();
    void setType(std::string newtype);
private:
    std::string type;
};

#endif