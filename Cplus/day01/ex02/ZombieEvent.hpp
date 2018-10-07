// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:02:36 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 22:02:37 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent();
    ~ZombieEvent();
    void    setZombieType(std::string str);
    std::string randomChump();
    Zombie* newZombie();

private:
    std::string _type;
};

#endif