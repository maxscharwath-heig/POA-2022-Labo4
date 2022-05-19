#ifndef POA_LABO4_FIELD_HPP
#define POA_LABO4_FIELD_HPP

class Field {
public:
    Field(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

    unsigned getHeight() const;

    unsigned getWidth() const;

    unsigned getNbHumans() const;

    unsigned getNbVampires() const;

private:
    const unsigned _height;
    const unsigned _width;
    const unsigned _nbHumans;
    const unsigned _nbVampire;
};


#endif //POA_LABO4_FIELD_HPP
