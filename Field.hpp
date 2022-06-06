#ifndef POA_LABO4_FIELD_HPP
#define POA_LABO4_FIELD_HPP

#include <list>
#include "character/Humanoid.hpp"

class Humanoid;

class Field {
public:
    Field(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    unsigned getHeight() const;

    unsigned getWidth() const;

    unsigned getNbHumans() const;

    unsigned getNbVampires() const;

    unsigned nextTurn();

    Humanoid** getHumanoid2DArray() const;

    void add(Humanoid* h);

    template<class T>
    T* getClosestHumanoid(Humanoid* humanoid) const;

    template<class T>
    int getNumberOfHumanoids() const;

    unsigned getTurn() const;

private:
   const unsigned _height;
   const unsigned _width;
   unsigned _nbHumans;
   unsigned _nbVampire;
   unsigned _turn = 0;

    std::list<Humanoid*> _humanoids;
};

template<class T>
T* Field::getClosestHumanoid(Humanoid* humanoid) const {
    T* closest = nullptr;
    for (auto& h: _humanoids) {
        if (h == humanoid || dynamic_cast<T*>(h) == nullptr)
            continue;
        if (closest == nullptr ||
            (humanoid->getX() - h->getX()) * (humanoid->getX() - h->getX()) +
            (humanoid->getY() - h->getY()) * (humanoid->getY() - h->getY()) <
            (humanoid->getX() - closest->getX()) * (humanoid->getX() - closest->getX()) +
            (humanoid->getY() - closest->getY()) * (humanoid->getY() - closest->getY()))
            closest = dynamic_cast<T*>(h);
    }
    return closest;
}

template<class T>
int Field::getNumberOfHumanoids() const {
    int nb = 0;
    for (auto& h: _humanoids) {
        if (dynamic_cast<T*>(h) != nullptr)
            nb++;
    }
    return nb;
}

#endif //POA_LABO4_FIELD_HPP
