// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 20:57:40 by akasamar          #+#    #+#             //
//   Updated: 2018/10/03 20:57:40 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
        if (ac != 4) {
            std::cout << "Error [usage]: <filename> <string-1> <string-2>" << std::endl;
        }
        else{
        std::string file = av[1];
        size_t lastindex = file.find_last_of(".");
        std::string rawname;
        if (lastindex != std::string::npos)
            rawname = file.substr(0, lastindex);
        else
            rawname = file;
        std::ofstream ofs(rawname + ".replace");
        std::ifstream ifs;
        ifs.open(av[1], std::ios::in);
        if (!ifs) {
            std::cout << "File error! Can't find, open or read one!" << std::endl;
        }
        std::string str1 = av[2];
        std::string str2 = av[3];
        std::string s((std::istreambuf_iterator<char>(ifs)),
                      std::istreambuf_iterator<char>());
        ifs.close();
        size_t pos;
        while (1)
        {
            pos = s.find(str1);
            if (pos == std::string::npos)
                break ;
            s.replace(s.find(str1), str2.size(), str2);
        }
        ofs << s;
        ofs.close();
    }

    return (0);
}

