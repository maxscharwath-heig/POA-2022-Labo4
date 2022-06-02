//
// Created by Maxime Scharwath on 02.06.2022.
//

#ifndef POA_LABO4_TRANSFORMACTION_HPP
#define POA_LABO4_TRANSFORMACTION_HPP


#include "Action.hpp"
#include "character/Human.hpp"

class TransformAction : public Action {
public:
    TransformAction(Human* h);

    void execute(Field& f) override;

    Human* target;
};


#endif //POA_LABO4_TRANSFORMACTION_HPP
