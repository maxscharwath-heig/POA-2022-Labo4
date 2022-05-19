#ifndef POA_LABO4_VAMPIRE_HPP
#define POA_LABO4_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : Humanoid {
public:
    void setAction(const Field* field) override;

    void executeAction(const Field* field) override;

    std::ostream& toStream(std::ostream& os) const override;
};


#endif //POA_LABO4_VAMPIRE_HPP
