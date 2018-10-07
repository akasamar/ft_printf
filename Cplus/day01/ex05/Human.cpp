// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 18:54:01 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 18:54:02 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human()
{
    return;
}

Human::~Human(){
    return ;
}

std::string   Human::identify()
{
    return br.identify();
}

Brain  Human::getBrain()
{
    return br;
}