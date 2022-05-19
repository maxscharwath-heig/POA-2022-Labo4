#ifndef POA_LABO4_VAMPIRE_HPP
#define POA_LABO4_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : public Humanoid {
public:
    Vampire(unsigned x, unsigned y);

    void setAction(const Field* field) override;

    void executeAction(const Field* field) override;

    std::ostream& toStream(std::ostream& os) const override;

    bool isAlive() const override;
};


#endif //POA_LABO4_VAMPIRE_HPP
