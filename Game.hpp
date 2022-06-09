#ifndef POA_LABO4_GAME_HPP
#define POA_LABO4_GAME_HPP

#include <ctime>
#include "Field.hpp"
#include "gui/FieldDisplayer.hpp"

/**
 * Class managing a game & simulation
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Game {
public:
    /**
     * Create an new game
     * @param height height of the board
     * @param width width of the board
     * @param nbHumans number of humans
     * @param nbVampires number of vampires
     */
    Game(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    /**
     * Destruct the game
     */
    ~Game();

    /**
     * Start the game interaction
     */
    void play();

private:
    /**
     * Simulate a number of games
     * @param count number of simulations
     * @param height height of the board
     * @param width width of the board
     * @param nbHumans number of humans
     * @param nbVampires number of vampires
     */
    static void simulate(unsigned count, unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    Field* _field;
    FieldDisplayer* _displayer;
};


#endif //POA_LABO4_GAME_HPP
