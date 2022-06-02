#ifndef POA_LABO4_GAME_HPP
#define POA_LABO4_GAME_HPP

#include "Field.hpp"
#include "gui/FieldDisplayer.hpp"

class Game {
public:
    Game(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires) {
        _field = new Field(height, width, nbHumans, nbVampires);
        _fieldDisplayer = new FieldDisplayer(*_field);
    }

    ~Game() {
        delete _field;
    }

    void play();

private:
    Field* _field;
    FieldDisplayer* _fieldDisplayer;
};


#endif //POA_LABO4_GAME_HPP
