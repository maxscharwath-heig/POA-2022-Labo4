#include "KillAction.hpp"

KillAction::KillAction(Humanoid* h) : _humanoid(h) {}

void KillAction::execute(Field& f) {
    _humanoid->kill();
}
