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

Fixed::Fixed(void)
{
    _rawBit = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {

    std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

int		Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
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