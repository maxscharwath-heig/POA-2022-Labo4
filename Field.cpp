#include <iostream>
#include "Field.hpp"
#include "character/Humanoid.hpp"
#include "character/Buffy.hpp"
#include "character/Human.hpp"
#include "character/Vampire.hpp"

Field::Field(unsigned int height, unsigned int width, unsigned int nbHumans, unsigned int nbVampires) : _height(height),
                                                                                                        _width(width),
                                                                                                        _nbHumans(
                                                                                                              nbVampires),
                                                                                                        _nbVampire(
                                                                                                              nbVampires) {

    add(new Buffy(rand() % _width, rand() % _height));

    for (size_t i = 0; i < nbHumans; ++i) {
        add(new Human(rand() % _width, rand() % _height));
    }

    for (size_t i = 0; i < nbVampires; ++i) {
        add(new Vampire(rand() % _width, rand() % _height));
    }
}

void Field::add(Humanoid* h) {
    _humanoids.emplace_back(h);
}

unsigned Field::nextTurn() {
    // Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->setAction(*this);
    }

    // Executer les actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->executeAction(*this);
    }

    // Enlever les humanoides tués et delete
    for (std::list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end();) {
        if (!(*it)->isAlive()) {
            delete (*it);
            it = _humanoids.erase(it);
        } else {
            ++it;
        }
    }

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

Humanoid** Field::getHumanoid2DArray() const {
    auto array = new Humanoid* [_height * _width];
    for (unsigned i = 0; i < _height * _width; i++) {
        array[i] = nullptr;
    }

    for (auto& humanoid: _humanoids) {
        if (humanoid->getX() >= _width || humanoid->getY() >= _height)
            continue;
        array[humanoid->getX() + humanoid->getY() * _width] = humanoid;
    }
    return array;
}

unsigned Field::getTurn() const {
    return _turn;
}