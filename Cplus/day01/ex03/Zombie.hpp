// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:02:21 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 22:02:22 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class   Zombie {
    public:
        Zombie();
        ~Zombie();
        void setZombieName(std::string str);
        void setZombieType(std::string str);
        void announce();
    private:
        std::string name;
        std::string type;
};

#endif
