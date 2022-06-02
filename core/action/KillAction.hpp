//
// Created by Maxime Scharwath on 12.05.2022.
//

#ifndef POA_LABO4_KILLACTION_HPP
#define POA_LABO4_KILLACTION_HPP


#include "Action.hpp"
#include "character/Humanoid.hpp"

class KillAction : public Action {
public:
    explicit KillAction(Humanoid* h);

    void execute(const Field& f) override;

private:
    Humanoid* _humanoid;
};


#endif //POA_LABO4_KILLACTION_HPP
