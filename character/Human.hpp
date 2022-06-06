#ifndef POA_LABO4_HUMAN_HPP
#define POA_LABO4_HUMAN_HPP


#include "Humanoid.hpp"

class Human : public Humanoid {
public:
    Human(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;
};


#endif //POA_LABO4_HUMAN_HPP
