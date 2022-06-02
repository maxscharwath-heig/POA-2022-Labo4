#include <iostream>
#include "Buffy.hpp"
#include "Human.hpp"

void Buffy::setAction(const Field& field) {
    auto h = field.getClosestHumanoid<Human>(this);
    if (h == nullptr) return;
    auto x = getX();
    auto y = getY();
    setX((x > h->getX()) ? x - 1 : x + 1);
    setY((y > h->getY()) ? y - 1 : y + 1);
}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mB\033[0m";
}

bool Buffy::isAlive() const {
    return true;
}

Buffy::Buffy(unsigned int x, unsigned int y) : Humanoid(x, y) {}

void Buffy::kill() {
    // I am Immortal MOUAHAHAHAH
}
