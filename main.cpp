#include <iostream>
#include "Game.hpp"

int main(int argc, char** argv) {
   unsigned height = argc > 1 ? std::stoi(argv[1]) : 30;
   unsigned width = argc > 2 ? std::stoi(argv[2]) : 50;
   unsigned nbHumans = argc > 3 ? std::stoi(argv[3]) : 10;
   unsigned nbVampires = argc > 4 ? std::stoi(argv[4]) : 10;

   Game game(height, width, nbHumans, nbVampires);
   game.play();

   return EXIT_SUCCESS;
}