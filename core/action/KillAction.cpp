//
// Created by Maxime Scharwath on 12.05.2022.
//

#include "KillAction.hpp"

KillAction::KillAction(Humanoid* h) : _humanoid(h) {}

void KillAction::execute(Field& f) {
    _humanoid->kill();
}
