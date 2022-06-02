#include "MoveAction.hpp"

MoveAction::MoveAction(Humanoid* who, unsigned x, unsigned y) : who(who), toX(x), toY(y) {
}

void MoveAction::execute(Field& f) {
    who->setX(toX);
    who->setY(toY);
}
