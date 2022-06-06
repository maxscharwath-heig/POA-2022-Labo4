#include "Kill.hpp"

Kill::Kill(Humanoid* h) : Action(h) {}

void Kill::execute(Field& f) {
   _target->kill();
}
