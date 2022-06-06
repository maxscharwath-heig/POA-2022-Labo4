#ifndef POA_LABO4_KILL_HPP
#define POA_LABO4_KILL_HPP

#include "Action.hpp"
#include "character/Humanoid.hpp"

class Kill : public Action {
public:
    explicit Kill(Humanoid* h);

    void execute(Field& f) override;
};


#endif //POA_LABO4_KILL_HPP
