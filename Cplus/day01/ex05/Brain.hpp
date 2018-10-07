// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 00:51:16 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 00:51:17 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
#include <string>
#include <sstream>

class Brain
{
public:
    Brain();
    ~Brain();
    std::string identify();
private:
    std::string adress;
};

#endif