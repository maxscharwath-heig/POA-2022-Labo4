#ifndef POA_LABO4_GAME_HPP
#define POA_LABO4_GAME_HPP

#include "Field.hpp"

class Game {
    const Field* _field;

public:
    Game(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires) {
        _field = new Field(height, width, nbHumans, nbVampires);
    }

    ~Game() {
        delete _field;
    }

};


#endif //POA_LABO4_GAME_HPP
