#include <limits>
#include <iostream>
#include "Game.hpp"
#include "character/Vampire.hpp"
#include "character/Human.hpp"
#include "Constants.hpp"
#include "Utils.hpp"
#include "FieldImpl.hpp"

Game::Game(unsigned int height, unsigned int width, unsigned int nbHumans, unsigned int nbVampires) {
    _field = new Field(height, width, nbHumans, nbVampires);
    _displayer = new FieldDisplayer();
}

Game::~Game() {
    delete _field;
    delete _displayer;
}

void Game::play() {
    bool continueLoop = true;

    do {
        clearScreen();
        _displayer->display(*_field);

        std::cout << "[" << _field->getTurn() << "]" << QUIT_LABEL << " " << STATISTICS_LABEL << " " << NEXT_LABEL
                  << std::endl;
        char c;
        std::cin >> c;
        if (!std::cin.fail()) {
            switch (c) {
                case QUIT_KEY:
                    continueLoop = false;
                    break;
                case STATISTICS_KEY:
                    simulate(10000,
                             _field->getHeight(),
                             _field->getHeight(),
                             _field->getNbHumans(),
                             _field->getNbVampires()
                    );
                    break;
                case NEXT_KEY:
                    _field->nextTurn();
                    break;
                default:
                    break;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (continueLoop);
}

void Game::simulate(unsigned int count, unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires) {

    unsigned nbLoses = 0;

    for (unsigned i = 1; i <= count; ++i) {
        Field simulation(height, width, nbHumans, nbVampires);
        bool hasVampireLeft = true;

        while (hasVampireLeft) {
            hasVampireLeft = simulation.getNumberOfHumanoids<Vampire>() > 0;
            bool hasHumansLeft = simulation.getNumberOfHumanoids<Human>() > 0;

            if (!hasHumansLeft) {
                ++nbLoses;
                break;
            }

            simulation.nextTurn();
        }
        // Show every 100 simulations
        if (i % 100 == 0) {
            clearScreen();
            std::cout << "[" << i << "]" << BUFFY_WINRATE << (1.0 - (double) nbLoses / (double) i) * 100.0 << '%'
                      << std::endl;
        }
    }

    std::cout << '\n' << PRESS_ENTER;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


