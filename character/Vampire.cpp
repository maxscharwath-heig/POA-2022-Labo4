#include <random>
#include "Vampire.hpp"
#include "Human.hpp"
#include "core/action/Move.hpp"
#include "core/action/Kill.hpp"
#include "core/action/Transform.hpp"

void Vampire::setAction(const Field& field) {
    auto h = field.getClosestHumanoid<Human>(this);
    if (h == nullptr) return;
    int speed = 1;
    int x = (int) getX();
    int y = (int) getY();
    int deltaX = (int) h->getX() - x;
    int deltaY = (int) h->getY() - y;
    if (abs(deltaX) <= 1 && abs(deltaY) <= 1) {
        if (std::bernoulli_distribution(0.5)(field.getRandomEngine())) {
            _nextAction = std::make_shared<Kill>(h);
        } else {
            _nextAction = std::make_shared<Transform>(h);
        }
    } else {
        x += std::min(std::max(deltaX, -speed), speed);
        y += std::min(std::max(deltaY, -speed), speed);
        _nextAction = std::make_shared<Move>(this, x, y);
    }
}

std::ostream& Vampire::toStream(std::ostream& os) const {
    return os << "\033[1;31mV\033[0m";
}

Vampire::Vampire(unsigned int x, unsigned int y) : Humanoid(x, y) {}