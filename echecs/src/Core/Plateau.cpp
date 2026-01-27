#include "Plateau.hpp"
#include <iostream>

Plateau::Plateau() {}

void Plateau::deplacer(int x1, int y1, int x2, int y2) {
    std::cout << "Deplacement de (" << x1 << "," << y1
              << ") vers (" << x2 << "," << y2 << ")\n";
}
