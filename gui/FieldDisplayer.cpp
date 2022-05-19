#include <iostream>
#include "FieldDisplayer.hpp"

FieldDisplayer::FieldDisplayer(const Field& field) : field(field) {
}

void FieldDisplayer::display() {
    unsigned width = field.getWidth();
    unsigned height = field.getHeight();
    for (unsigned i = 0; i < height; i++) {
        for (unsigned j = 0; j < width; j++) {
            if ((i == 0 && (j == 0 || j == width - 1)) || (i == height - 1 && (j == 0 || j == width - 1))) {
                std::cout << "+";
            } else if (i == 0 || i == height - 1) {
                std::cout << "-";
            } else if (j == 0 || j == width - 1) {
                std::cout << "¦";
            } else {
                // inside
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
