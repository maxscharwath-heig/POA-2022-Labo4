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
    int deltaX = (int) v->getX() - (int) getX();
    int deltaY = (int) v->getY() - (int) getY();
    if (abs(deltaX) <= 1 && abs(deltaY) <= 1) {
        _nextAction = std::make_shared<Kill>(v);
    } else {
        _nextAction = std::make_shared<Move>(
              this,
              getX() + std::min(std::max(deltaX, -speed), speed),
              getY() + std::min(std::max(deltaY, -speed), speed)
        );
    }
}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mB\033[0m";
}

Buffy::Buffy(unsigned int x, unsigned int y) : Human(x, y) {}

void Buffy::kill() {
    // I am Immortal
}
