#include "Move.hpp"

Move::Move(Humanoid* h, unsigned x, unsigned y) : Action(h), toX(x), toY(y) {}

void Move::execute(Field& f) {
   _target->setX(toX);
   _target->setY(toY);
}
