#include "Field.hpp"

Field::Field(unsigned int height, unsigned int width, unsigned int nbHumans, unsigned int nbVampires) : _height(height),
                                                                                                        _width(width),
                                                                                                        _nbHumans(
                                                                                                              nbVampires),
                                                                                                        _nbVampire(
                                                                                                              nbVampires) {

}

unsigned Field::getHeight() const {
    return _height;
}

unsigned Field::getWidth() const {
    return _width;
}

unsigned Field::getNbHumans() const {
    return _nbHumans;
}

unsigned Field::getNbVampires() const {
    return _nbVampire;
}