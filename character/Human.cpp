#include "Human.hpp"

void Human::setAction(const Field* field) {

}

void Human::executeAction(const Field* field) {

}

std::ostream& Human::toStream(std::ostream& os) const {
    return os << "\033[1;35mH\033[0m";
}

bool Human::isAlive() const {
    return true;
}

Human::Human(unsigned int x, unsigned int y) : Humanoid(x, y) {

}
