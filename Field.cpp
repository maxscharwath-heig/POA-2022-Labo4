#include "Field.hpp"
#include "character/Humanoid.hpp"

Field::Field(unsigned int height, unsigned int width, unsigned int nbHumans, unsigned int nbVampires) : _height(height),
                                                                                                        _width(width),
                                                                                                        _nbHumans(
                                                                                                              nbVampires),
                                                                                                        _nbVampire(
                                                                                                              nbVampires) {

}

unsigned Field::nextTurn() {
    // Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        // (*it)->setAction(*this);

    // Executer les actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        // (*it)->executeAction(*this);

    // Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end();)
        if (!(*it)->isAlive()) {
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
        } else
            ++it;

    return ++_turn;
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