#include <iostream>
#include "Humanoid.hpp"

Humanoid::Humanoid(unsigned x, unsigned y) : _posX(x), _posY(y), _nextAction(nullptr) {}

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

void Humanoid::setNextAction(Action* action) {
    delete _nextAction;
    _nextAction = action;
}

void Humanoid::executeAction(Field& field) {
    if (_nextAction != nullptr) {
        _nextAction->execute(field);
        delete _nextAction;
        _nextAction = nullptr;
    }
}

bool Humanoid::isAlive() const {
   return _alive;
}

void Humanoid::kill() {
   _alive = false;
}

std::ostream& operator<<(std::ostream& os, const Humanoid& h) {
    return h.toStream(os);
}

