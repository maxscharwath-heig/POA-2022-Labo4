//
// Created by Maxime Scharwath on 02.06.2022.
//

#include "TransformAction.hpp"
#include "character/Vampire.hpp"

TransformAction::TransformAction(Human* h) {
    this->target = h;
}

void TransformAction::execute(Field& f) {
    target->kill();
    f.add(new Vampire(target->getX(), target->getY()));
}
