#include "Interface.hpp"

#include <imgui.h>
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

Interface::Interface()
    : fenetre(nullptr), rendu(nullptr), selection(false) {}

Interface::~Interface() {}

void Interface::initialiser() {
    SDL_Init(SDL_INIT_VIDEO);

    fenetre = SDL_CreateWindow(
        "Jeu d'echecs - SDL3",
        800,
        800,
        SDL_WINDOW_RESIZABLE
    );

    rendu = SDL_CreateRenderer(fenetre, nullptr);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplSDL3_InitForSDLRenderer(fenetre, rendu);
    ImGui_ImplSDLRenderer3_Init(rendu);
}

void Interface::evenements(bool& enCours, Plateau& plateau) {
    SDL_Event event;
    int sx = -1, sy = -1;

    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);

        if (event.type == SDL_EVENT_QUIT) {
            enCours = false;
        }

        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            int x = event.button.x / 100;
            int y = event.button.y / 100;

            if (!selection) {
                sx = x;
                sy = y;
                selection = true;
            } else {
                plateau.deplacer(sx, sy, x, y);
                selection = false;
            }
        }
    }
}

void Interface::dessiner(const Plateau&) {
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            SDL_FRect caseRect {
                x * 100.0f,
                y * 100.0f,
                100.0f,
                100.0f
            };

            if ((x + y) % 2 == 0)
                SDL_SetRenderDrawColor(rendu, 240, 217, 181, 255);
            else
                SDL_SetRenderDrawColor(rendu, 181, 136, 99, 255);

            SDL_RenderFillRect(rendu, &caseRect);
        }
    }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Infos");
    ImGui::Text("Projet Echecs");
    ImGui::Text("SDL3 + ImGui");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), rendu);

    SDL_RenderPresent(rendu);
}

void Interface::nettoyer() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}
