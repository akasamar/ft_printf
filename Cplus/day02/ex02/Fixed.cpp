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

bool	Fixed::operator>(Fixed const & rhs)
{
    return (this->_rawBit > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs)
{
    return (this->_rawBit < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs)
{
    return (this->_rawBit >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs)
{
    return (this->_rawBit <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs)
{
    return (this->_rawBit == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs)
{
    return (this->_rawBit != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
    Fixed	ret;

    ret.setRawBits(this->_rawBit + rhs._rawBit);
    return (ret);
}

Fixed 	Fixed::operator-(Fixed const & rhs)
{
    Fixed   ret;

    ret.setRawBits(this->_rawBit - rhs._rawBit);
    return (ret);
}

Fixed 	Fixed::operator*(Fixed const & rhs)
{
    Fixed   ret;

    ret._rawBit = (this->_rawBit * rhs._rawBit) >> this->_bit;;
    return (ret);
}

Fixed 	Fixed::operator/(Fixed const & rhs)
{
    Fixed   ret;

    ret._rawBit = (this->_rawBit << this->_bit) / rhs._rawBit;
    return (ret);
}

Fixed &		Fixed::operator++(void)
{
    this->_rawBit++;
    return (*this);
}

Fixed		Fixed::operator++(int)
{
    Fixed	newfix;

    newfix = *this;
    this->_rawBit++;
    return (newfix);
}

Fixed &		Fixed::operator--(void)
{
    this->_rawBit--;
    return (*this);
}

Fixed		Fixed::operator--(int)
{
    Fixed	newfix;

    newfix = *this;
    this->_rawBit++;
    return (newfix);
}

const Fixed & 	Fixed::min(Fixed const & low, Fixed const & high)
{
    if (low.getRawBits() > high.getRawBits())
        return (high);
    return (low);
}

const Fixed & 	Fixed::max(Fixed const & low, Fixed const & high)
{
    if (low.getRawBits() > high.getRawBits())
        return (low);
    return (high);
}