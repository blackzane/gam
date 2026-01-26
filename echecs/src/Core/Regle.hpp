#include "Regles.hpp"
#include <cmath>

bool Regles::coupValide(const Plateau& plateau, const Coup& coup)
{
    Piece piece = plateau.obtenirPiece(coup.xDepart, coup.yDepart);
    if (piece.type == TypePiece::Aucune)
        return false;

    int dx = std::abs(coup.xArrivee - coup.xDepart);
    int dy = std::abs(coup.yArrivee - coup.yDepart);

    switch (piece.type) {
    case TypePiece::Tour: return dx == 0 || dy == 0;
    case TypePiece::Fou: return dx == dy;
    case TypePiece::Reine: return dx == dy || dx == 0 || dy == 0;
    case TypePiece::Roi: return dx <= 1 && dy <= 1;
    case TypePiece::Cavalier: return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    case TypePiece::Pion: return dy == 1;
    default: return false;
    }
}
