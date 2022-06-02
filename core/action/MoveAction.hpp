#ifndef POA_LABO4_MOVEACTION_HPP
#define POA_LABO4_MOVEACTION_HPP

#include "Action.hpp"
#include "character/Humanoid.hpp"

class MoveAction : public Action {
public:
    MoveAction(Humanoid* h, unsigned x, unsigned y);

    void execute(const Field& f) override;

private:
    Humanoid* who;
    const unsigned toX;
    const unsigned toY;
};


#endif //POA_LABO4_MOVEACTION_HPP
