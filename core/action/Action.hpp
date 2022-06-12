#ifndef POA_LABO4_ACTION_HPP
#define POA_LABO4_ACTION_HPP

#include "Field.hpp"

class Field;

class Humanoid;

/**
 * Class representing a simulation action, performed on an humanoid
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Action {
public:

   /**
    * Prepare an action on a target humanoid
    * @param target target humanoid
    */
   explicit Action(Humanoid* target);

   virtual ~Action() = default;

   /**
    * Execute the action
    * @param f the simulation field
    */
   virtual void execute(Field& f) = 0;

protected:
   Humanoid* _target;
};


#endif //POA_LABO4_ACTION_HPP
