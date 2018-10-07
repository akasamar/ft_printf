// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:02:31 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 22:02:32 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

std::string ZombieEvent::randomChump()
{
    std::string name[] = {"petya", "vasya", "galya", "sveta", "nina"};
    return name[rand() % 4];
};

void     ZombieEvent::setZombieType(std::string str)
{
    _type = str;
}

Zombie*  ZombieEvent::newZombie()
{
    Zombie *zmb = new Zombie();
    zmb->setZombieName(ZombieEvent::randomChump());
    zmb->setZombieType(_type);
    zmb->announce();
    return zmb;
}

ZombieEvent::ZombieEvent()
{
    _type = "Default type";
    std::cout << "ZombieEvent constructor started." << std::endl;
}

ZombieEvent::~ZombieEvent()
{
    std::cout << "ZombieEvent destructor called." << std::endl;
}