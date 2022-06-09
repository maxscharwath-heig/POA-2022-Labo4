#include <random>
#include "Vampire.hpp"
#include "Human.hpp"
#include "core/action/Move.hpp"
#include "core/action/Kill.hpp"
#include "core/action/Transform.hpp"

void Vampire::setAction(const Field& field) {
    auto h = field.getClosestHumanoid<Human>(this);
    if (h == nullptr) return;
    unsigned x = getX();
    unsigned y = getY();

    if (abs((int) x - (int) h->getX()) <= 1 && abs((int) y - (int) h->getY()) <= 1) {//TODO: check if this is correct
        if (std::bernoulli_distribution(0.5)(field.getRandomEngine())) {
            _nextAction = std::make_shared<Kill>(h);
        } else {
            _nextAction = std::make_shared<Transform>(h);
        }
    } else {
        if (x != h->getX()) x += x > h->getX() ? -1 : 1;
        if (y != h->getY()) y += y > h->getY() ? -1 : 1;
        _nextAction = std::make_shared<Move>(this, x, y);
    }
}

std::ostream& Vampire::toStream(std::ostream& os) const {
    return os << "\033[1;31mV\033[0m";
}

Vampire::Vampire(unsigned int x, unsigned int y) : Humanoid(x, y) {}