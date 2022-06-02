#include <iostream>
#include "Human.hpp"
#include "core/action/MoveAction.hpp"

void Human::setAction(const Field& field) {
    delete nextAction; // delete previous
    int nextX, nextY;

    do {
        nextX = getX() + rand() % 3 - 1;
        nextY = getY() + rand() % 3 - 1;

    } while ((nextX == 0 && nextY == 0)
             || nextX < 0 || nextX >= field.getWidth()
             || nextY < 0 || nextY >= field.getHeight());

    nextAction = new MoveAction(this, nextX, nextY);
}

void Human::executeAction(const Field& field) {
    nextAction->execute(field);
}

std::ostream& Human::toStream(std::ostream& os) const {
    return os << "\033[1;35mH\033[0m";
}

bool Human::isAlive() const {
    return alive;
}

Human::Human(unsigned int x, unsigned int y) : Humanoid(x, y) {

}

void Human::kill() {
    alive = false;
}
