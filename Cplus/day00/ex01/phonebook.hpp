// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   phonebook.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 16:57:34 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 16:57:35 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class   Abonent
{
public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string post_adress;
    std::string email_adress;
    std::string phone_number;
    std::string birth_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
};


#endif