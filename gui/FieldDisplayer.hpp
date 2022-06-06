#ifndef POA_LABO4_FIELDDISPLAYER_HPP
#define POA_LABO4_FIELDDISPLAYER_HPP

#include "Field.hpp"

class FieldDisplayer {
public:
    void display(const Field& field) const;

    void clear();

private:
    static const char CORNER = '+';
    static const char HORIZONTAL = '-';
    static const char VERTICAL = '|';
    static const char EMPTY = ' ';
};


#endif //POA_LABO4_FIELDDISPLAYER_HPP
