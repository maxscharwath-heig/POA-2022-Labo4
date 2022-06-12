#ifndef POA_LABO4_FIELD_HPP
#define POA_LABO4_FIELD_HPP

#include <list>
#include <random>
#include <typeinfo> // typeid
#include "character/Humanoid.hpp"

class Humanoid;

/**
 * Class that represent a simulation field
 *
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 */
class Field {
public:
   /**
    * Create a new field
    * @param height height of field
    * @param width width of field
    * @param nbHumans number of human to add on the field
    * @param nbVampires number of vampires to add on the field
    */
   Field(unsigned height, unsigned width, unsigned nbHumans, unsigned nbVampires);

   /**
    * Destruct the field
    */
   ~Field();

   /**
    * Get the height of the field
    * @return height of the field
    */
   unsigned getHeight() const;

   /**
    * Get the width of the field
    * @return width of the field
    */
   unsigned getWidth() const;

   /**
   * Get the number of humans on the field
   * @return number of humans
   */
   unsigned getNbHumans() const;

   /**
   * Get the number of vampires on the field
   * @return number of vampires
   */
   unsigned getNbVampires() const;

   /**
    * Run the next round of the simulation
    * @return next round's number
    */
   unsigned nextTurn();

   /**
    * Get the current turn's number
    * @return current turn's number
    */
   unsigned getTurn() const;

   /**
    * Get the random engine
    * @return random engin
    */
   std::default_random_engine& getRandomEngine() const;

   /**
    * Get the humanoids on the field as a 2D array
    * @return humanoids on the field
    */
   Humanoid** getHumanoid2DArray() const;

   /**
    * Add an humanoid to the field
    * @param h humanoid to add
    */
   void add(Humanoid* h);

   /**
    * Get the closest humanoid from an humanoid
    * @tparam T exact type of humanoid to search
    * @param humanoid the humanoid to use for distance to
    * @return closest humanoid type if it exists, else nullptr
    */
   template <class T>
   T* getClosestHumanoid(Humanoid* humanoid) const;

   /**
    * Get the number of alive humanoid on the field
    *
    * @tparam T exact type of humanoid to search
    * @return number of humanoid type on the field
    */
   template <class T>
   int getNumberOfHumanoids() const;

private:
   const unsigned _height;
   const unsigned _width;
   unsigned _nbHumans;
   unsigned _nbVampire;
   unsigned _turn = 0;
   std::default_random_engine* eng;
   std::list<Humanoid*> _humanoids;
};

template <class T>
T* Field::getClosestHumanoid(Humanoid* humanoid) const {
   T* closest = nullptr;
   for (auto& h: _humanoids) {
      if (h == humanoid || typeid(*h) != typeid(T))
         continue;
      if (closest == nullptr ||
          (humanoid->getX() - h->getX()) * (humanoid->getX() - h->getX()) +
          (humanoid->getY() - h->getY()) * (humanoid->getY() - h->getY()) <
          (humanoid->getX() - closest->getX()) * (humanoid->getX() - closest->getX()) +
          (humanoid->getY() - closest->getY()) * (humanoid->getY() - closest->getY()))
         closest = dynamic_cast<T*>(h);
   }
   return closest;
}

template <class T>
int Field::getNumberOfHumanoids() const {
   int nb = 0;
   for (auto& h: _humanoids) {
      if (typeid(*h) == typeid(T))
         nb++;
   }
   return nb;
}

#endif //POA_LABO4_FIELD_HPP
