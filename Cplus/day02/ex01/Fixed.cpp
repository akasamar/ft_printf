// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 15:32:14 by akasamar          #+#    #+#             //
//   Updated: 2018/10/04 15:32:15 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    _rawBit = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(f * (1 << _bit)));
}

Fixed::Fixed(int const i)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(i << _bit);
}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

int		Fixed::getRawBits(void) const {

    return this->_rawBit;
}

void    Fixed::setRawBits(int const raw) {

    this->_rawBit = raw;
}

Fixed & Fixed::operator=(Fixed const &fx)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fx)
        this->_rawBit = fx.getRawBits();
    return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

int		Fixed::toInt(void) const
{
    return (getRawBits() >> this->_bit);
}

float	Fixed::toFloat(void) const
{
    float	n;

    n = getRawBits();
    return (n / (1 << this->_bit));
}