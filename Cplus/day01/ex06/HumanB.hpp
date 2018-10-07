// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Humanb.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:47:31 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:47:31 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& gun);
private:
    Weapon *gun;
    std::string name;
};

#endif