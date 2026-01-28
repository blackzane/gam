#include <SDL3/SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "Board.h"
#include <iostream>

// --- 1. FONCTION DE DESSIN DES SYMBOLES (Doit être en haut) ---
void drawPieceLabel(SDL_Renderer* r, PieceType type, float x, float y) {
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // Rouge pour les lettres
    switch (type) {
        case PieceType::Pawn:   // 'P'
            SDL_RenderLine(r, x, y, x, y+10); 
            SDL_RenderLine(r, x, y, x+5, y);
            SDL_RenderLine(r, x, y+5, x+5, y+5);
            break;
        case PieceType::Rook:   // 'R'
            SDL_RenderLine(r, x, y, x, y+10);
            SDL_RenderLine(r, x, y, x+5, y);
            break;
        case PieceType::Knight: // 'N'
            SDL_RenderLine(r, x, y, x, y+10);
            SDL_RenderLine(r, x, y, x+5, y+10);
            SDL_RenderLine(r, x+5, y, x+5, y+10);
            break;
        case PieceType::King:   // '+'
            SDL_RenderLine(r, x-5, y+5, x+5, y+5);
            SDL_RenderLine(r, x, y, x, y+10);
            break;
        case PieceType::Queen:  // 'Q'
            SDL_RenderRect(r, new SDL_FRect{x, y, 6, 6});
            break;
        default: break;
    }
}

// --- 2. FONCTION DE RENDU DU PLATEAU ---
void drawBoard(SDL_Renderer* renderer, Board& board, int selectedSquare) {
    const int tileSize = 80;
    for (int i = 0; i < 64; i++) {
        int row = i / 8;
        int col = i % 8;
        float x = (float)col * tileSize;
        float y = (float)row * tileSize;

        // Couleur des cases
        if (i == selectedSquare) {
            SDL_SetRenderDrawColor(renderer, 186, 202, 43, 255);
        } else if ((row + col) % 2 == 0) {
            SDL_SetRenderDrawColor(renderer, 235, 235, 208, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 119, 148, 85, 255);
        }

        SDL_FRect rect = {x, y, (float)tileSize, (float)tileSize};
        SDL_RenderFillRect(renderer, &rect);

        // Dessin des pièces
        Piece p = board.squares[i];
        if (p.type != PieceType::None) {
            if (p.color == Color::White) 
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else 
                SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
            
            SDL_FRect pRect = {x + 20, y + 20, 40, 40};
            SDL_RenderFillRect(renderer, &pRect);
            
            // Marquage de la pièce
            drawPieceLabel(renderer, p.type, x + 37, y + 35);
        }
    }
}

// --- 3. MAIN ---
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Chess Game", 640, 640, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    Board board;
    Color currentTurn = Color::White;
    int selectedSquare = -1;
    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT) running = false;

            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && !ImGui::GetIO().WantCaptureMouse) {
                int col = (int)(event.button.x / 80);
                int row = (int)(event.button.y / 80);
                int idx = row * 8 + col;

                if (idx >= 0 && idx < 64) {
                    if (selectedSquare == -1) {
                        if (board.squares[idx].color == currentTurn) selectedSquare = idx;
                    } else {
                        if (board.canMove(selectedSquare, idx, currentTurn)) {
                            board.squares[idx] = board.squares[selectedSquare];
                            board.squares[selectedSquare] = {PieceType::None, Color::None};
                            currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;
                        }
                        selectedSquare = -1;
                    }
                }
            }
        }

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
        
        ImGui::Begin("Info");
        ImGui::Text("Tour : %s", (currentTurn == Color::White ? "BLANCS" : "NOIRS"));
        if (ImGui::Button("Reset")) { board.reset(); currentTurn = Color::White; }
        ImGui::End();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        drawBoard(renderer, board, selectedSquare);
        
        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
    }

    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}