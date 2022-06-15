#include <iostream>
#include "Game.hpp"

/**
 * Entry point of the program.
 * Labs #4 - Buffy the Vampire Slayer
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
int main(int argc, char** argv) {
    unsigned height, width, nbHumans, nbVampires;

    if (argc == 5) { // If the user gave the parameters
        height = std::stoul(argv[1]);
        width = std::stoul(argv[2]);
        nbHumans = std::stoul(argv[3]);
        nbVampires = std::stoul(argv[4]);
    }
    else if (argc == 1) { // Default values
        height = 50;
        width = 50;
        nbHumans = 20;
        nbVampires = 10;
    }
    else { // If the user gave wrong parameters
        std::cout << "Usage: " << argv[0] << " <height> <width> <nbHumans> <nbVampires>" << std::endl;
        return EXIT_FAILURE;
    }

    Game game(height, width, nbHumans, nbVampires);
    game.play();

    return EXIT_SUCCESS;
}