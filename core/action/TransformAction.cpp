#include "TransformAction.hpp"
#include "character/Vampire.hpp"

TransformAction::TransformAction(Human* h) {
    this->target = h;
}

void TransformAction::execute(Field& f) {
    target->kill();
    f.add(new Vampire(target->getX(), target->getY()));
}
