#include "Buffy.hpp"

void Buffy::setAction(const Field* field) {

}

void Buffy::executeAction(const Field* field) {

}

std::ostream& Buffy::toStream(std::ostream& os) const {
    return os << "\033[1;33mBuffy\033[0m";
}
