// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:02:16 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 22:02:17 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie with name was killed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << "<" << name << " ("<< type << ")" << "> " << "Braiiiiiiinnnssss..." << std::endl;
}

void    Zombie::setZombieName(std::string str)
{
    name = str;
}

void    Zombie::setZombieType(std::string str)
{
    type = str;
}