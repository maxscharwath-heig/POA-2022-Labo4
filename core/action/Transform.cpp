#include "Transform.hpp"
#include "character/Vampire.hpp"

Transform::Transform(Human* h) : Kill(h) {}

void Transform::execute(Field& f) {
    if (_target->isAlive())
        f.add(new Vampire(_target->getX(), _target->getY()));

    Kill::execute(f);
}
