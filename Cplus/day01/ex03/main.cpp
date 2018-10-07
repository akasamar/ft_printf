// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 17:28:27 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 17:28:28 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main(void)
{
    ZombieHorde zombaki = ZombieHorde(5);
    zombaki.announce();
    return 0;
}