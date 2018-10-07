// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:16:48 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 18:16:49 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

void ponyOnTheHeap(void)
{
    Pony *pepa = new Pony("Bitch", "Pink", 1.42);
    pepa->ponySay("good wheather!");
    delete pepa;
}

void ponyOnTheStack(void)
{
    Pony pepa2 = Pony("Kolya", "Gray", 0.55);
    pepa2.changeParamPony("Vasya", "Pink");
}

int main(void)
{
    std::cout << "ponyOnTheHeap starting.." << std::endl;
    ponyOnTheHeap();
    std::cout << "ponyOnTheHeap finished" << std::endl;
    std::cout << "ponyOnTheStack starting.." << std::endl;
    ponyOnTheStack();
    std::cout << "ponyOnTheStack finished" << std::endl;
    return (0);
}