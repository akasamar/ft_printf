// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 14:51:06 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 14:51:08 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <iostream>

int main (int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
            for (int k = 0; argv[i][k]; k++)
            {
                if (argv[i][k] >= 97 && argv[i][k] <= 122)
                    std:: cout << (char)(argv[i][k] - 32);
                else
                    std:: cout << argv[i][k];
            }
    }
    std::cout << std::endl;
    return (1);
}
