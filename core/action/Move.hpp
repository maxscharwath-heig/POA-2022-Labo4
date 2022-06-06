#ifndef POA_LABO4_MOVE_HPP
#define POA_LABO4_MOVE_HPP

#include "Action.hpp"
#include "character/Humanoid.hpp"

class Move : public Action {
public:
    Move(Humanoid* h, unsigned x, unsigned y);

    void execute(Field& f) override;

private:
    const unsigned toX;
    const unsigned toY;
};


#endif //POA_LABO4_MOVE_HPP
