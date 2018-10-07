// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:17:02 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 18:17:03 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class   Pony
{
public:
    Pony (std::string name, std::string color, float height);
    ~Pony();
    std::string color;
    std::string name;
    void    changeParamPony(std::string name, std::string color);
    void    ponySay(std::string str);

private:
    float height;
};


#endif