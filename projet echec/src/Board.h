#pragma once
#include <vector>
#include <cmath>

enum class PieceType { None, Pawn, Rook, Knight, Bishop, Queen, King };
enum class Color { None, White, Black };

struct Piece {
    PieceType type = PieceType::None;
    Color color = Color::None;
};

class Board {
public:
    Piece squares[64];
    Board() { reset(); }
    void reset();
    bool canMove(int from, int to, Color turn);
};