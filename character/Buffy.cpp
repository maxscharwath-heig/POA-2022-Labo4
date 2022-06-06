#include <iostream>
#include "Buffy.hpp"
#include "Vampire.hpp"
#include "core/action/Kill.hpp"
#include "core/action/Move.hpp"

void Buffy::setAction(const Field& field) {
    auto v = field.getClosestHumanoid<Vampire>(this);
    if (v == nullptr) return;

    unsigned x = getX();
    unsigned y = getY();

    if (abs((int) x - (int) v->getX()) <= 1 && abs((int) y - (int) v->getY()) <= 1) { //TODO: check if this is correct
        setNextAction(new Kill(v));
    } else {
        if (x != v->getX()) x += x > v->getX() ? -1 : 1;
        if (y != v->getY()) y += y > v->getY() ? -1 : 1;
        setNextAction(new Move(this, x, y));
    }
}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mB\033[0m";
}

Buffy::Buffy(unsigned int x, unsigned int y) : Humanoid(x, y) {}

void Buffy::kill() {
    // I am Immortal
}
