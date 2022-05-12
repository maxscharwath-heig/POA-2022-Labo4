cmake_minimum_required(VERSION 3.22)
project(POA_Labo4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(POA_Labo4
        Humanoid.cpp
        Humanoid.hpp
        Field.cpp
        Field.hpp
        main.cpp)
