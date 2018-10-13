// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 14:23:25 by akasamar          #+#    #+#             //
//   Updated: 2018/10/13 14:23:26 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSE_HPP
#define NCURSE_HPP

#define STR1 "     /\__/\"
#define STR2 "    /`    '\"
#define STR3 "  === 0  0 ==="
#define STR4 "    \  --  /"
#define STR5 "   /        \"
#define STR6 "  /          \"
#define STR7 " |            |"
#define STR8 "  \  ||  ||  /"
#define STR9 "   \_oo__oo_/#######o"

#include <iostream>
#include <string>
#include <ncurses.h>
#include "App.hpp"
#include <zconf.h>




class Ncurse{
public:
    Ncurse();
    ~Ncurse();
    Ncurse(Ncurse const & src);
    Ncurse & operator=(Ncurse const & src);

    void    setWin1(WINDOW *win1);
    void    setWin2(WINDOW *win2);
    void    setWin3(WINDOW *win3);
    void    setWin4(WINDOW *win4);

    WINDOW*    getWin1();
    WINDOW*    getWin2();
    WINDOW*    getWin3();
    WINDOW*    getWin4();

    void        inputDiagram(WINDOW *win, int data);
    void        start_ncurse_mode();
private:
    WINDOW* _win1;
    WINDOW* _win2;
    WINDOW* _win3;
    WINDOW* _win4;
    int * FirstArray;
    int * SecondArray;

    void create_win();
    void checkSizeWindow();
};

void start_ncurse_mode();

#endif