#ifndef POA_LABO4_KILL_HPP
#define POA_LABO4_KILL_HPP

#include "Action.hpp"
#include "character/Humanoid.hpp"

/**
 * Class representing the killing of an humanoid
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Kill : public Action {
public:
    /**
     * Prepare the kill of an humanoid
     */
    explicit Kill(Humanoid* h);

    /**
     * Kill the humanoid
     * @param f the simulation field
     */
    void execute(Field& f) override;
};


#endif //POA_LABO4_KILL_HPP
