// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 00:51:03 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 00:51:04 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
#define HUMAN_HPP
# include "Brain.hpp"

class Human{
public:
    Human(void);
    ~Human(void);

    std::string    identify(void);
    Brain   getBrain();
private:
    Brain br;
};

#endif