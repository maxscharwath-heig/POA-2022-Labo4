#include "Humanoid.hpp"

Humanoid::Humanoid() : nextAction(nullptr) {}

std::ostream& operator<<(std::ostream& os, const Humanoid& h) {
    return h.toStream(os);
}

