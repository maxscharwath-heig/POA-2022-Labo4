#ifndef POA_LABO4_FIELDIMPL_HPP
#define POA_LABO4_FIELDIMPL_HPP

// This file is used to write the definition of templated methods of Field.hpp

#include "Field.hpp"

template <class T>
T* Field::getClosestHumanoid(Humanoid* humanoid) const {
    T* closest = nullptr;
    for (auto& h: _humanoids) {
        if (h == humanoid || typeid(*h) != typeid(T))
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

template <class T>
unsigned Field::getNumberOfHumanoids() const {
    unsigned nb = 0;
    for (auto& h: _humanoids) {
        if (typeid(*h) == typeid(T))
            nb++;
    }
    return nb;
}

#endif //POA_LABO4_FIELDIMPL_HPP
