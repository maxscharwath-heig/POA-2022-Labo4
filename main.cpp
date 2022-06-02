#include <iostream>
#include <limits>
#include "Field.hpp"
#include "gui/FieldDisplayer.hpp"

void clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

int main() {
    std::cout << "\033[1;33mBuffy\033[0m" << std::endl;
    std::cout << "\033[1;35mHuman\033[0m" << std::endl;
    std::cout << "\033[1;31mVampire\033[0m" << std::endl;

    //create a field
    Field field(30, 50, 10, 10);
    FieldDisplayer fieldDisplayer(field);

    //todo put this in a function
    bool continueLoop = true;
    do {
        clear();
        fieldDisplayer.display();
        std::cout << "[0] q>uit s>tatistics n>ext : ";
        char c;
        std::cin >> c;
        if (!std::cin.fail()) {
            switch (c) {
                case 'q': //quit
                    continueLoop = false;
                    break;
                case 's': //statistics
                    break;
                case 'n': //next
                    break;
                default: //do nothing
                    break;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continueLoop);
    return EXIT_SUCCESS;
}