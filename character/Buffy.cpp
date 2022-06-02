#include <iostream>
#include "Buffy.hpp"
#include "Vampire.hpp"

void Buffy::setAction(const Field& field) {
    auto v = field.getClosestHumanoid<Vampire>(this);
    if (v != nullptr) {
        std::cout << "Buffy at " << getX() << " " << getY() << " is going to attack " << v->getX() << " " << v->getY()
                  <<
                  std::endl;
    }
}

void Buffy::executeAction(const Field& field) {

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
