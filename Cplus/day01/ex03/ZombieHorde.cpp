// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 17:28:20 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 17:28:21 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    std::cout << "ZombieHorde constructor started." << std::endl;
    num = n;
    ptr = new Zombie[n];
    return ;
}

ZombieHorde::~ZombieHorde(void) {
    std::cout << "Destrutor started and will delete all objects." << std::endl;
    delete [] ptr;
}

void ZombieHorde::announce() {
    std::string array[7] = {"vasya", "katya", "sisya", "pisya", "lalka", "churka", "pepa"};
    for (int i = 0; i < num; i++)
    {
        ptr[i].setZombieType("Default Type");
        ptr[i].setZombieName(array[rand() % 7]);
        ptr[i].announce();
    }
}