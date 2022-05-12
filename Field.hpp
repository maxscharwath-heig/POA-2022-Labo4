#ifndef POA_LABO4_FIELD_HPP
#define POA_LABO4_FIELD_HPP

class Field {
public:
    Field(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

private:
    const unsigned _height;
    const unsigned _width;
    const unsigned _nbHumans;
    const unsigned _nbVampire;
};


#endif //POA_LABO4_FIELD_HPP
