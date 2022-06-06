#ifndef POA_LABO4_TRANSFORMACTION_HPP
#define POA_LABO4_TRANSFORMACTION_HPP


#include "Action.hpp"
#include "character/Human.hpp"

class TransformAction : public Action {
public:
    explicit TransformAction(Human* h);

    void execute(Field& f) override;

    Human* target;
};


#endif //POA_LABO4_TRANSFORMACTION_HPP
