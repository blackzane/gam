#pragma once
#include "Piece.hpp"

class Plateau {
private:
    Piece grille[8][8];

public:
    void initialiser();
    Piece obtenir(int x, int y) const;
    void deplacer(int x1, int y1, int x2, int y2);
};
