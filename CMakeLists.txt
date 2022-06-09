cmake_minimum_required(VERSION 3.22)
project(POA_Labo4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(POA_Labo4
        character/Humanoid.cpp character/Humanoid.hpp
        character/Human.cpp character/Human.hpp
        character/Vampire.cpp character/Vampire.hpp
        character/Buffy.cpp character/Buffy.hpp
        gui/FieldDisplayer.hpp gui/FieldDisplayer.cpp
        core/action/Action.cpp core/action/Action.hpp
        core/action/Kill.cpp core/action/Kill.hpp
        core/action/Move.cpp core/action/Move.hpp
        core/action/Transform.cpp core/action/Transform.hpp
        Field.cpp Field.hpp
        Game.hpp Game.cpp
        main.cpp core/utils.hpp)
