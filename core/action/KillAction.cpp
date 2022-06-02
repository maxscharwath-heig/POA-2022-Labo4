//
// Created by Maxime Scharwath on 12.05.2022.
//

#include "KillAction.hpp"
#include "character/Vampire.hpp"

KillAction::KillAction(Humanoid* h) {
    _humanoid = h;
}

void KillAction::execute(const Field& f) {
    f.getClosestHumanoid<Vampire>(_humanoid);
    _humanoid->kill();
}
