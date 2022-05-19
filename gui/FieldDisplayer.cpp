#include <iostream>
#include "FieldDisplayer.hpp"

FieldDisplayer::FieldDisplayer(const Field& field) : field(field) {
}

void FieldDisplayer::display() {
    auto humanoids = field.getHumanoid2DArray();
    unsigned width = field.getWidth() + 2;
    unsigned height = field.getHeight() + 2;
    for (unsigned i = 0; i < height; i++) {
        for (unsigned j = 0; j < width; j++) {
            if ((i == 0 && (j == 0 || j == width - 1)) || (i == height - 1 && (j == 0 || j == width - 1))) {
                std::cout << "+";
            } else if (i == 0 || i == height - 1) {
                std::cout << "-";
            } else if (j == 0 || j == width - 1) {
                std::cout << "¦";
            } else {
                unsigned x = j - 1;
                unsigned y = i - 1;
                auto humanoid = humanoids[x + y * field.getWidth()];
                if (humanoid != nullptr) {
                    std::cout << *humanoid;
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    delete humanoids;
}
