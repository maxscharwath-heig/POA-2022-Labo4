#ifndef POA_LABO4_VAMPIRE_HPP
#define POA_LABO4_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Class representing a vampire
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Vampire : public Humanoid {
public:
    /**
     * Create a new vampire at position
     * @param x x coordinate
     * @param y y coordinate
     */
    Vampire(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;
};


#endif //POA_LABO4_VAMPIRE_HPP
