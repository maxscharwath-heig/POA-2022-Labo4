#include <iostream>
#include "Human.hpp"

void Human::setAction(const Field& field) {
    // Random between -1 et 1
    // Random new x
    int randomNum = rand() % 3 + (-1);

    std::cout << randomNum;

    // const MoveAction next(this, );
    // setNextAction()
}

void Human::executeAction(const Field& field) {

}

std::ostream& Human::toStream(std::ostream& os) const {
    return os << "\033[1;35mH\033[0m";
}

bool Human::isAlive() const {
    return true;
}

Human::Human(unsigned int x, unsigned int y) : Humanoid(x, y) {

}
