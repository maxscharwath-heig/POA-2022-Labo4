#ifndef POA_LABO4_BUFFY_HPP
#define POA_LABO4_BUFFY_HPP


#include "Human.hpp"

/**
 * Class representing Buffy "the vampire slayer"
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Buffy : public Human {
public:
   /**
    * Create a new buffy at position
    * @param x x coordinate
    * @param y y coordinate
    */
    Buffy(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;

    /**
     * Buffy cannot be killed
     */
    void kill() override;
};


#endif //POA_LABO4_BUFFY_HPP
