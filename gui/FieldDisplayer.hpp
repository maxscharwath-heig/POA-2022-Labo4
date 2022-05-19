#ifndef POA_LABO4_FIELDDISPLAYER_HPP
#define POA_LABO4_FIELDDISPLAYER_HPP


#include "Field.hpp"

class FieldDisplayer {
public:
    explicit FieldDisplayer(const Field& field);

    void display();

private:
    const Field& field;

};


#endif //POA_LABO4_FIELDDISPLAYER_HPP
