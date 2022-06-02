#include <iostream>
#include "Game.hpp"

int main() {
    /*
    std::cout << "\033[1;33mBuffy\033[0m" << std::endl;
    std::cout << "\033[1;35mHuman\033[0m" << std::endl;
    std::cout << "\033[1;31mVampire\033[0m" << std::endl;
     */

    Game game(30, 50, 10, 10);
    game.play();

    return EXIT_SUCCESS;
}