#ifndef POA_LABO4_HUMAN_HPP
#define POA_LABO4_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Class representing an human
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Human : public Humanoid {
public:
    /**
     * Create a new human at position
     * @param x x coordinate
     * @param y y coordinate
     */
    Human(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;
};


#endif //POA_LABO4_HUMAN_HPP
