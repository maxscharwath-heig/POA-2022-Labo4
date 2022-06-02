//
// Created by Maxime Scharwath on 12.05.2022.
//

#include "Vampire.hpp"

void Vampire::setAction(const Field& field) {
}

void Vampire::executeAction(const Field& field) {
}

std::ostream& Vampire::toStream(std::ostream& os) const {
    return os << "\033[1;31mV\033[0m";
}

bool Vampire::isAlive() const {
    return true;
}

Vampire::Vampire(unsigned int x, unsigned int y) : Humanoid(x, y) {}
