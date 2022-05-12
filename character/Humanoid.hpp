#ifndef POA_LABO4_HUMANOID_HPP
#define POA_LABO4_HUMANOID_HPP


#include "Field.hpp"

class Humanoid {
public:
    virtual ~Humanoid() = default;

    virtual void setAction(const Field* field) = 0;

    virtual void executeAction(const Field* field) = 0;
};


#endif //POA_LABO4_HUMANOID_HPP
