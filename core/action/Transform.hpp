#ifndef POA_LABO4_TRANSFORM_HPP
#define POA_LABO4_TRANSFORM_HPP


#include "Action.hpp"
#include "character/Human.hpp"
#include "Kill.hpp"

class Transform : public Kill {
public:
    explicit Transform(Human* h);

    void execute(Field& f) override;
};


#endif //POA_LABO4_TRANSFORM_HPP
