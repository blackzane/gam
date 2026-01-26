#include "Interface.hpp"
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

static SDL_Texture* charger(SDL_Renderer* r, const char* chemin)
{
    SDL_Surface* s = IMG_Load(chemin);
    if (!s) return nullptr;
    SDL_Texture* t = SDL_CreateTextureFromSurface(r, s);
    SDL_DestroySurface(s);
    return t;
}

void Interface::initialiser()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    fenetre = SDL_CreateWindow("Echecs", 800, 800, 0);
    rendu = SDL_CreateRenderer(fenetre, nullptr);

    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(fenetre, rendu);
    ImGui_ImplSDLRenderer3_Init(rendu);

    textures["blanc_pion"] = charger(rendu, "assets/pieces/blanc_pion.png");
    textures["noir_pion"]  = charger(rendu, "assets/pieces/noir_pion.png");

    son = Mix_LoadWAV("assets/sons/clic.wav");
    selection = false;
}

void Interface::evenements(bool& enCours, Plateau& plateau)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        ImGui_ImplSDL3_ProcessEvent(&e);
        if (e.type == SDL_EVENT_QUIT) enCours = false;

        if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            int x = e.button.x / 100;
            int y = e.button.y / 100;
            Mix_PlayChannel(-1, son, 0);

            if (!selection) { sx = x; sy = y; selection = true; }
            else { plateau.deplacer(sx, sy, x, y); selection = false; }
        }
    }
}

void Interface::dessiner(const Plateau& plateau)
{
    SDL_RenderClear(rendu);

    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++) {
            SDL_Rect c{ x*100, y*100, 100, 100 };
            bool clair = (x+y)%2==0;
            SDL_SetRenderDrawColor(rendu, clair?220:80, clair?220:80, clair?220:80, 255);
            SDL_RenderFillRect(rendu, &c);

            Piece p = plateau.obtenir(x,y);
            if (p.type == TypePiece::Pion) {
                SDL_Rect d{ x*100+10, y*100+10, 80, 80 };
                SDL_RenderTexture(rendu,
                    p.couleur==Couleur::Blanc?textures["blanc_pion"]:textures["noir_pion"],
                    nullptr,&d);
            }
        }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Menu");
    ImGui::Text("Jeu d'Echecs");
    ImGui::End();
    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());

    SDL_RenderPresent(rendu);
}

void Interface::nettoyer()
{
    for (auto& t : textures) SDL_DestroyTexture(t.second);
    Mix_FreeChunk(son);
    Mix_CloseAudio();
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}
