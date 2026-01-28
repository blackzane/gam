#include "Board.h"

void Board::reset() {
    // Placement standard (on garde l'init pour avoir les pièces au départ)
    for (int i = 0; i < 64; i++) squares[i] = {PieceType::None, Color::None};
    
    PieceType backline[] = {PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen, 
                            PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook};
    
    for (int i = 0; i < 8; i++) {
        squares[i]      = {backline[i], Color::Black}; // Ligne 0
        squares[i + 8]  = {PieceType::Pawn,  Color::Black}; // Ligne 1
        squares[i + 48] = {PieceType::Pawn,  Color::White}; // Ligne 6
        squares[i + 56] = {backline[i], Color::White}; // Ligne 7
    }
}

bool Board::canMove(int from, int to, Color turn) {
    if (squares[from].color != turn) return false;
    if (squares[to].color == turn) return false;

    int fromRow = from / 8; int toRow = to / 8;
    int fromCol = from / 8; int toCol = to % 8; // Correction index
    int diffRow = toRow - fromRow;
    int diffCol = std::abs((to % 8) - (from % 8));

    if (squares[from].type == PieceType::Pawn) {
        // Blancs montent (-1), Noirs descendent (+1)
        int direction = (turn == Color::White) ? -1 : 1;
        // Avancer d'une case
        if (diffCol == 0 && diffRow == direction && squares[to].type == PieceType::None) return true;
        // Manger en diagonale
        if (diffCol == 1 && diffRow == direction && squares[to].type != PieceType::None) return true;
        return false;
    }

    return true; // Les autres pièces restent libres pour l'instant
}
