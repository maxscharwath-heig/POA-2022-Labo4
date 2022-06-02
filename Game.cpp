#include <limits>
#include <iostream>
#include <thread>
#include "Game.hpp"

void Game::play() {
    bool continueLoop = true;
    bool autoPlay = false;
    do {
        FieldDisplayer::clear();
        _fieldDisplayer->display();
        if (autoPlay) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            _field->nextTurn();
            continue;
        }
        std::cout << "[" << _field->getTurn() << "] q>uit s>tatistics n>ext : ";
        char c;
        std::cin >> c;
        if (!std::cin.fail()) {
            switch (c) {
                case 'a':
                    autoPlay = true;
                    break;
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
