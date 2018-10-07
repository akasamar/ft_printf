// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 15:32:18 by akasamar          #+#    #+#             //
//   Updated: 2018/10/04 15:32:19 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(Fixed const &fx);
    ~Fixed(void);

    Fixed & operator=(Fixed const & fx);

    int		getRawBits(void) const;
    void	setRawBits(int const raw);


private:
    static int const _bit = 8;
    int _rawBit;
};

#endif
