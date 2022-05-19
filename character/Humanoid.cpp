#include "Humanoid.hpp"

Humanoid::Humanoid() : nextAction(nullptr) {}

unsigned int Humanoid::getX() const {
    return 10;
}

unsigned int Humanoid::getY() const {
    return 10;
}

std::ostream& operator<<(std::ostream& os, const Humanoid& h) {
    return h.toStream(os);
}

