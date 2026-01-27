#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <SDL3/SDL.h>
#include "Core/Plateau.hpp"

class Interface {
public:
    Interface();
    ~Interface();

    void initialiser();
    void evenements(bool& enCours, Plateau& plateau);
    void dessiner(const Plateau& plateau);
    void nettoyer();

private:
    SDL_Window* fenetre;
    SDL_Renderer* rendu;
    bool selection;
};

#endif
