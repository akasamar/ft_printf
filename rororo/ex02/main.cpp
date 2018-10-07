// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 15:32:03 by akasamar          #+#    #+#             //
//   Updated: 2018/10/04 15:32:04 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "\n[a and b with increment and decrement:]" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "[Min and Max result:]" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;


    Fixed c(3);
    Fixed d(2);
    std::cout << "\n[c and d values:]" << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n[* and / result:]" << std::endl;
    std::cout << "c * d = " << (c * d) << std::endl;
    std::cout << "c / d = " << (c / d) << std::endl;

    std::cout << "\n[+ and - result:]" << std::endl;
    std::cout << "c + d = " << (c + d) << std::endl;
    std::cout << "c - d = " << (c - d) << std::endl;


    std::cout << "\n[> < == != >= <= signs:]" << std::endl;
    if (c > d)
        std::cout << "c > d" << std::endl;
    if (c >= d)
        std::cout << "c >= d" << std::endl;
    if (d < c)
        std::cout << "c < d" << std::endl;
    if (d <= c)
        std::cout << "c <= d" << std::endl;
    if (d == c)
        std::cout << "c == d" << std::endl;
    if (d != c)
        std::cout << "c != d" << std::endl;
    return (0);
}