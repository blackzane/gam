#include "Plateau.hpp"

void Plateau::initialiser()
{
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            grille[y][x] = {};

    for (int x = 0; x < 8; x++) {
        grille[1][x] = {TypePiece::Pion, Couleur::Noir};
        grille[6][x] = {TypePiece::Pion, Couleur::Blanc};
    }
}

Piece Plateau::obtenir(int x, int y) const
{
    return grille[y][x];
}

void Plateau::deplacer(int x1, int y1, int x2, int y2)
{
    grille[y2][x2] = grille[y1][x1];
    grille[y1][x1] = {};
}
