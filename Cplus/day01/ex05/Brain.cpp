// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 00:51:22 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 00:51:23 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"

std::string   Brain::identify()
{
    return adress;
}

Brain::Brain()
{
    std::stringstream loh;
    loh << this;
    adress = loh.str();
}

Brain::~Brain()
{
    return ;
}
