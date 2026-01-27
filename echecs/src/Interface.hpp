#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <map>
#include <string>

#include "Core/Plateau.hpp"

class Interface {
private:
    SDL_Window* fenetre;
    SDL_Renderer* rendu;

    std::map<std::string, SDL_Texture*> textures;
    Mix_Chunk* sonClic;

    bool selection;
    int xSel, ySel;

public:
    void initialiser();
    void evenements(bool& enCours, Plateau& plateau);
    void dessiner(const Plateau& plateau);
    void nettoyer();
};

#endif
