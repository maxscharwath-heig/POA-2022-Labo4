#ifndef POA_LABO4_ACTION_HPP
#define POA_LABO4_ACTION_HPP

#include "Field.hpp"

class Field;

class Humanoid;

class Action {
public:

    explicit Action(Humanoid* target);

    virtual ~Action() = default;

    virtual void execute(Field& f) = 0;

protected:
    Humanoid* _target;
};


#endif //POA_LABO4_ACTION_HPP
