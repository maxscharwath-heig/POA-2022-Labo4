#ifndef POA_LABO4_BUFFY_HPP
#define POA_LABO4_BUFFY_HPP


#include "Human.hpp"

class Buffy : public Human {
public:
    Buffy(unsigned x, unsigned y);

    void setAction(const Field& field) override;

    std::ostream& toStream(std::ostream& os) const override;

    void kill() override;
};


#endif //POA_LABO4_BUFFY_HPP
