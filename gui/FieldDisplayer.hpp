#ifndef POA_LABO4_FIELDDISPLAYER_HPP
#define POA_LABO4_FIELDDISPLAYER_HPP


#include "Field.hpp"

class FieldDisplayer {
public:
    explicit FieldDisplayer(const Field& field);

    void display();

    void static clear() {
#if defined _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

private:
    const Field& field;
};


#endif //POA_LABO4_FIELDDISPLAYER_HPP
