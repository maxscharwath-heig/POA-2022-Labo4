#include <iostream>
#include "Field.hpp"
#include "gui/FieldDisplayer.hpp"

int main() {
    std::cout << "\033[1;33mBuffy\033[0m" << std::endl;
    std::cout << "\033[1;35mHuman\033[0m" << std::endl;
    std::cout << "\033[1;31mVampire\033[0m" << std::endl;

    //create a field
    Field field(50, 50, 10, 10);
    FieldDisplayer fieldDisplayer(field);
    fieldDisplayer.display();
    return EXIT_SUCCESS;
}