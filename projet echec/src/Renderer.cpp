#include <SDL3/SDL.h>
#include "Board.h"

void drawBoard(SDL_Renderer* renderer, Board& board) {
    int tileSize = 80;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // Dessin de la case
            if ((row + col) % 2 == 0)
                SDL_SetRenderDrawColor(renderer, 235, 235, 208, 255); // Beige
            else
                SDL_SetRenderDrawColor(renderer, 119, 148, 85, 255);  // Vert échecs

            SDL_FRect rect = {(float)col * tileSize, (float)row * tileSize, (float)tileSize, (float)tileSize};
            SDL_RenderFillRect(renderer, &rect);

            // Dessin de la pièce (temporaire : un cercle ou un carré)
            Piece p = board.squares[row * 8 + col];
            if (p.type != PieceType::None) {
                if (p.color == Color::White) SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                else SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                
                SDL_FRect pRect = {(float)col * tileSize + 20, (float)row * tileSize + 20, 40, 40};
                SDL_RenderFillRect(renderer, &pRect);
            }
        }
    }
}