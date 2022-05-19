#ifndef POA_LABO4_ACTION_HPP
#define POA_LABO4_ACTION_HPP


#include "Field.hpp"

class Field;

class Action {
public:
    virtual ~Action() = default;

    virtual void execute(const Field& f) = 0;
};


#endif //POA_LABO4_ACTION_HPP
