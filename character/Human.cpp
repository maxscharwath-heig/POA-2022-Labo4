#include <iostream>
#include <random>
#include "Human.hpp"
#include "core/action/Move.hpp"

void Human::setAction(const Field& field) {
    //create a vector with all possible moves
    std::vector<std::pair<unsigned, unsigned>> nextPositions;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int x = (int) getX() + i;
            int y = (int) getY() + j;
            if (x < 0 || x >= field.getWidth() || y < 0 || y >= field.getHeight()) continue;
            nextPositions.emplace_back(x, y);
        }
    }
    //randomly select a move
    if (!nextPositions.empty()) {
        std::uniform_int_distribution<int> distribution(0, nextPositions.size() - 1);
        int index = distribution(field.getRandomEngine());
        _nextAction = std::make_shared<Move>(this, nextPositions[index].first, nextPositions[index].second);
    }
}

std::ostream& Human::toStream(std::ostream& os) const {
    return os << "\033[1;35mH\033[0m";
}

Human::Human(unsigned int x, unsigned int y) : Humanoid(x, y) {

}
