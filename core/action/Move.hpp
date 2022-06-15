#ifndef POA_LABO4_MOVE_HPP
#define POA_LABO4_MOVE_HPP

#include "Action.hpp"
#include "character/Humanoid.hpp"

/**
 * Class representing a move of an humanoid
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Move : public Action {
public:
    /**
     * Prepare a move of an humanoid
     * @param h humanoid to move
     * @param x x coordinate of move
     * @param y y coordinate of move
     */
    Move(Humanoid* h, unsigned x, unsigned y);

    /**
     * Move the humanoid
     * @param f the simulation field
     */
    void execute(Field& f) override;

private:
    const unsigned toX;
    const unsigned toY;
};


#endif //POA_LABO4_MOVE_HPP
