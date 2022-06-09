#include <iostream>
#include "Buffy.hpp"
#include "Vampire.hpp"
#include "core/action/Kill.hpp"
#include "core/action/Move.hpp"

void Buffy::setAction(const Field& field) {
    auto v = field.getClosestHumanoid<Vampire>(this);
    if (v == nullptr) {
        Human::setAction(field);
        return;
    }

    int speed = 2;
    int x = (int) getX();
    int y = (int) getY();
    int deltaX = (int) v->getX() - x;
    int deltaY = (int) v->getY() - y;
    if (abs(deltaX) <= 1 && abs(deltaY) <= 1) {
        _nextAction = std::make_shared<Kill>(v);
    } else {
        x += std::min(std::max(deltaX, -speed), speed);
        y += std::min(std::max(deltaY, -speed), speed);
        _nextAction = std::make_shared<Move>(this, x, y);
    }
}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mB\033[0m";
}

Buffy::Buffy(unsigned int x, unsigned int y) : Human(x, y) {}

void Buffy::kill() {
    // I am Immortal
}
