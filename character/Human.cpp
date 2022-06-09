#include <iostream>
#include <random>
#include "Human.hpp"
#include "core/action/Move.hpp"

void Human::setAction(const Field& field) {
    int nextX, nextY;
    std::uniform_int_distribution<> moveDist(-1, 1);
    do {
        nextX = (int) getX() + moveDist(field.getRandomEngine());
        nextY = (int) getY() + moveDist(field.getRandomEngine());

    } while ((nextX == 0 && nextY == 0)
             || nextX < 0 || nextX >= field.getWidth()
             || nextY < 0 || nextY >= field.getHeight());

    _nextAction = std::make_shared<Move>(this, nextX, nextY);
}

std::ostream& Human::toStream(std::ostream& os) const {
    return os << "\033[1;35mH\033[0m";
}

Human::Human(unsigned int x, unsigned int y) : Humanoid(x, y) {

}
