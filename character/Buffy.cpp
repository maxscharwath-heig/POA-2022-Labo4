#include "Buffy.hpp"

void Buffy::setAction(const Field& field) {

}

void Buffy::executeAction(const Field& field) {

}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mB\033[0m";
}

bool Buffy::isAlive() const {
    return true;
}

Buffy::Buffy(unsigned int x, unsigned int y) : Humanoid(x, y) {}
