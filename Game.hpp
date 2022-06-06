#ifndef POA_LABO4_GAME_HPP
#define POA_LABO4_GAME_HPP

#include <ctime>
#include "Field.hpp"
#include "gui/FieldDisplayer.hpp"

class Game {
public:
    Game(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    ~Game();

    void play();

   void simulate(unsigned count, unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

private:
    Field* _field;
    FieldDisplayer* _fieldDisplayer;
};


#endif //POA_LABO4_GAME_HPP
