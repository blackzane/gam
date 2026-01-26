#pragma once

enum class TypePiece {
    Roi, Reine, Tour, Fou, Cavalier, Pion, Aucune
};

enum class Couleur {
    Blanc, Noir, Aucune
};

struct Piece {
    TypePiece type = TypePiece::Aucune;
    Couleur couleur = Couleur::Aucune;
};
