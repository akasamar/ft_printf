// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:17:13 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 18:17:13 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

Pony::Pony(std::string newname, std::string newcolor, float newheight)
{
    this->name = newname;
    this->color = newcolor;
    this->height = newheight;
    std::cout << "Constructor called. Name, color and height was initializied." << std::endl;
}

Pony::~Pony()
{
    std::cout << "Destructor called." << std::endl;
}

void Pony::ponySay(std::string str) {
    std::cout << "privet, my name is " << name << " and i say you " << str << std::endl;
}

void    Pony::changeParamPony(std::string name, std::string color)
{
    this->name = name;
    this->color = color;
    std::cout << "Parameters of Pony were changed." << std::endl;
}