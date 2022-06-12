#ifndef POA_LABO4_FIELDDISPLAYER_HPP
#define POA_LABO4_FIELDDISPLAYER_HPP

#include "Field.hpp"
#include "Constants.hpp"

/**
 * Class used to display a simulation field
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class FieldDisplayer {
public:

   /**
    * Display a field
    * @param field the field to display
    */
   void display(const Field& field) const;

   /**
    * Clear the display
    */
   static void clear();
};


#endif //POA_LABO4_FIELDDISPLAYER_HPP
