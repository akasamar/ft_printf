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
    Fixed(int const i);
    Fixed(float const f);
    Fixed(Fixed const &fx);
    ~Fixed(void);


    float	toFloat(void) const;
    int		toInt(void) const;
    int		getRawBits(void) const;
    void	setRawBits(int const raw);

    bool		operator==(Fixed const & fx);
    bool		operator!=(Fixed const & fx);
    bool		operator>(Fixed const & fx);
    bool		operator<(Fixed const & fx);
    bool		operator>=(Fixed const & fx);
    bool		operator<=(Fixed const & fx);

    Fixed 		operator-(Fixed const & fx);
    Fixed 		operator*(Fixed const & fx);
    Fixed 		operator+(Fixed const & fx);
    Fixed 		operator/(Fixed const & fx);
    Fixed &		operator=(Fixed const & fx);
    Fixed &		operator--(void);
    Fixed		operator--(int);
    Fixed &		operator++(void);
    Fixed		operator++(int);

    static Fixed & 			min(Fixed & lhs, Fixed & rhs);
    static Fixed & 			max(Fixed & lhs, Fixed & rhs);
    static const Fixed & 	min(Fixed const & lhs, Fixed const & rhs);
    static const Fixed & 	max(Fixed const & lhs, Fixed const & rhs);

private:
    static int const _bit = 8;
    int _rawBit;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
