// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:48:30 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:48:31 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
    return ;
}

HumanB::~HumanB() {
    return ;
}

void    HumanB::attack() {
    std::cout << name << " attacks with his " << gun->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& gun)
{
    this->gun = &gun;
}