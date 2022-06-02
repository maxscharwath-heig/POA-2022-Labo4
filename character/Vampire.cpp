//
// Created by Maxime Scharwath on 12.05.2022.
//

#include "Vampire.hpp"
#include "Human.hpp"
#include "core/action/MoveAction.hpp"
#include "core/action/KillAction.hpp"
#include "core/action/TransformAction.hpp"

void Vampire::setAction(const Field& field) {
    auto h = field.getClosestHumanoid<Human>(this);
    if (h == nullptr) return;
    unsigned x = getX();
    unsigned y = getY();

    //if human is one case length of vampire
    if (abs((int) x - (int) h->getX()) == 1 && abs((int) y - (int) h->getY()) == 1) {
        if (rand() % 2 == 0) {
            setNextAction(new KillAction(h));
        } else {
            setNextAction(new TransformAction(h));
        }
    } else {
        x += x > h->getX() ? -1 : 1;
        y += y > h->getY() ? -1 : 1;
        setNextAction(new MoveAction(this, x, y));
    }
}

std::ostream& Vampire::toStream(std::ostream& os) const {
    return os << "\033[1;31mV\033[0m";
}

bool Vampire::isAlive() const {
    return _alive;
}

Vampire::Vampire(unsigned int x, unsigned int y) : Humanoid(x, y) {}

void Vampire::kill() {
    _alive = false;
}
