#include <limits>
#include <iostream>
#include "Game.hpp"

void Game::play() {
    bool continueLoop = true;
    do {
        FieldDisplayer::clear();
        _fieldDisplayer->display();
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
                    _field->nextTurn();
                    break;
                default: //do nothing
                    break;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continueLoop);
}
