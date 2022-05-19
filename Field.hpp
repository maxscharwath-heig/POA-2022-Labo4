#ifndef POA_LABO4_FIELD_HPP
#define POA_LABO4_FIELD_HPP

#include <list>
#include "character/Humanoid.hpp"

class Humanoid;

class Field {
public:
    Field(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    unsigned nextTurn();

private:
    const unsigned _height;
    const unsigned _width;
    const unsigned _nbHumans;
    const unsigned _nbVampire;
    unsigned _turn;

    std::list<Humanoid*> _humanoids;
};


#endif //POA_LABO4_FIELD_HPP
