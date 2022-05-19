#ifndef POA_LABO4_HUMANOID_HPP
#define POA_LABO4_HUMANOID_HPP

#include <ostream>
#include "Field.hpp"
#include "core/action/Action.hpp"

class Action;

class Field;

class Humanoid {
    const Action* nextAction;
public:
    virtual ~Humanoid() = default;

    virtual void setAction(const Field* field) = 0;

    virtual void executeAction(const Field* field) = 0;

    virtual void setNextAction(const Action* action) {
        nextAction = action;
    }

    virtual bool isAlive() const = 0;

    virtual std::ostream& toStream(std::ostream& os) const = 0;

    unsigned getX() const;

    unsigned getY() const;

    void setX(unsigned x);

    void setY(unsigned y);

protected:
    Humanoid(unsigned x, unsigned y);


private:
    unsigned _posX;
    unsigned _posY;
};

std::ostream& operator<<(std::ostream& os, const Humanoid& h);


#endif //POA_LABO4_HUMANOID_HPP
