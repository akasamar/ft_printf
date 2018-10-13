cmake_minimum_required(VERSION 3.12)
project(rush01)

set(CMAKE_CXX_STANDARD 14)

add_executable(rush01
        main.cpp
        create_monitor.cpp
        Ncurse.hpp
        Ncurse.cpp
        App.cpp
        App.hpp)
