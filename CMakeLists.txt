cmake_minimum_required(VERSION 3.22)
project(POA_Labo4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(POA_Labo4
        character/Humanoid.cpp character/Humanoid.hpp
        character/Human.cpp character/Human.hpp
        character/Vampire.cpp character/Vampire.hpp
        character/Buffy.cpp character/Buffy.hpp
        core/Action.cpp core/Action.hpp
        Field.cpp Field.hpp
        main.cpp)
