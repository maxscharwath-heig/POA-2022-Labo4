#ifndef POA_LABO4_FIELDDISPLAYER_HPP
#define POA_LABO4_FIELDDISPLAYER_HPP

#include "Field.hpp"
#include "Constants.hpp"

class FieldDisplayer {
public:
    void display(const Field& field) const;

    static void clear();
};


#endif //POA_LABO4_FIELDDISPLAYER_HPP
