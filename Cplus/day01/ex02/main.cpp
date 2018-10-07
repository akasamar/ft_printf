// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:02:58 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 22:03:00 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"

int main(void)
{
    Zombie *zmb;
    Zombie *zmb2;
    ZombieEvent event;
    event.setZombieType("churka");
    zmb = event.newZombie();
    event.setZombieType("Lox");
    zmb2 = event.newZombie();
    delete zmb;
    delete zmb2;
    return (0);
}