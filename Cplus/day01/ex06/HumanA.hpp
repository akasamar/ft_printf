// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:47:26 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 19:47:26 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon& gun);
    ~HumanA();
    void attack();
    void setWeapon(Weapon gun);
private:
    Weapon& gun;
    std::string name;
};

#endif