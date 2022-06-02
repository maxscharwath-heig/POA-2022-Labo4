#ifndef POA_LABO4_BUFFY_HPP
#define POA_LABO4_BUFFY_HPP


#include "Humanoid.hpp"

class Buffy : public Humanoid {
public:
    Buffy(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    void executeAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;

    bool isAlive() const override;
};


#endif //POA_LABO4_BUFFY_HPP
