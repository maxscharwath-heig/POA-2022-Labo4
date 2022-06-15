#include <limits>
#include <iostream>
#include "Game.hpp"
#include "character/Vampire.hpp"
#include "character/Human.hpp"
#include "Constants.hpp"

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
    bool autoPlay = false;

    do {
        FieldDisplayer::clear();
        _displayer->display(*_field);

        if (autoPlay) {
            _field->nextTurn();
            continue;
        }

        std::cout << "[" << _field->getTurn() << "]" << QUIT_LABEL << " " << STATISTICS_LABEL << " " << NEXT_LABEL << std::endl;
        char c;
        std::cin >> c;
        if (!std::cin.fail()) {
            switch (c) {
                case 'a':
                    autoPlay = true;
                    break;
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
        //show every 100 simulations
        if (i % 100 == 0) {
            FieldDisplayer::clear();
            std::cout << "[" << i << "]" << "buffy winrate :" << (1.0 - (double) nbLoses / (double) i) * 100.0 << '%'
                      << std::endl;
        }
    }
}


