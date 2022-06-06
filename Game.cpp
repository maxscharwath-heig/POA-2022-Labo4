#include <limits>
#include <iostream>
#include <thread>
#include "Game.hpp"
#include "character/Vampire.hpp"
#include "character/Human.hpp"

Game::Game(unsigned int height, unsigned int width, unsigned int nbHumans, unsigned int nbVampires) {
    srand(time(nullptr));
    _field = new Field(height, width, nbHumans, nbVampires);
    _fieldDisplayer = new FieldDisplayer();
}

Game::~Game() {
    delete _field;
    delete _fieldDisplayer;
}

void Game::play() {
    bool continueLoop = true;
    bool autoPlay = false;

    do {
        _fieldDisplayer->clear();
        _fieldDisplayer->display(*_field);

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
                    simulate(10000,
                             _field->getHeight(),
                             _field->getHeight(),
                             _field->getNbHumans(),
                             _field->getNbVampires()
                    );
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

void Game::simulate(unsigned int count, unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires) {

    Human tmp(0, 0);
    unsigned nbLoses = 0;

    for (unsigned i = 1; i <= count; ++i) {
        Field simulation(height, width, nbHumans, nbVampires);

        bool hasVampireLeft = true;
        bool hasHumansLeft;

        while (hasVampireLeft) {

            simulation.nextTurn();

            hasVampireLeft = simulation.getClosestHumanoid<Vampire>(&tmp) != nullptr;
            hasHumansLeft = simulation.getClosestHumanoid<Human>(&tmp) != nullptr;

            if (!hasHumansLeft) {
                ++nbLoses;
                break;
            }
        }
        std::cout << "buffy winrate :" << (i - nbLoses) << "%" << std::endl;
    }
}


