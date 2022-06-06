#include "Vampire.hpp"
#include "Human.hpp"
#include "core/action/Move.hpp"
#include "core/action/Kill.hpp"
#include "core/action/Transform.hpp"

void Vampire::setAction(const Field& field) {
   auto h = field.getClosestHumanoid<Human>(this);
   if (h == nullptr) return;
   unsigned x = getX();
   unsigned y = getY();

   //if human is one case length of vampire
   if (abs((int) x - (int) h->getX()) <= 1 && abs((int) y - (int) h->getY()) <= 1) {//TODO: check if this is correct
      if (rand() % 2 == 0) {
         setNextAction(new Kill(h));
      }
      else {
         setNextAction(new Transform(h));
      }
   }
   else {
      if (x != h->getX()) x += x > h->getX() ? -1 : 1;
      if (y != h->getY()) y += y > h->getY() ? -1 : 1;
      setNextAction(new Move(this, x, y));
   }
}

std::ostream& Vampire::toStream(std::ostream& os) const {
   return os << "\033[1;31mV\033[0m";
}

Vampire::Vampire(unsigned int x, unsigned int y) : Humanoid(x, y) {}