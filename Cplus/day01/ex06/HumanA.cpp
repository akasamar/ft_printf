// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:47:18 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:47:19 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& gun) : name(name), gun(gun) {
    return ;
}

HumanA::~HumanA() {
    return ;
}

void    HumanA::attack() {
    std::cout << name << " attacks with his " << gun.getType() << std::endl;
}
