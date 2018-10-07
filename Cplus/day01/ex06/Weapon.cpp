// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:49:16 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:49:17 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

#include <string>
#include <iostream>

Weapon::Weapon(std::string type) : type(type) {
    return ;
}

Weapon::~Weapon() {
    return ;
}

std::string Weapon::getType()
{
    return type;
}

void        Weapon::setType(std::string newtype)
{
    type = newtype;
}