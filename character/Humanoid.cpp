#include "Humanoid.hpp"

Humanoid::Humanoid(unsigned x, unsigned y) : _posX(x), _posY(y), nextAction(nullptr) {}

void Humanoid::setX(unsigned int x) {
    _posX = x;
}

void Humanoid::setY(unsigned int y) {
    _posY = y;
}

unsigned Humanoid::getX() const {
    return _posX;
}

unsigned Humanoid::getY() const {
    return _posY;
}

std::ostream& operator<<(std::ostream& os, const Humanoid& h) {
    return h.toStream(os);
}

