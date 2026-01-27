#include <SDL3/SDL.h>
#include <iostream>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Erreur SDL\n";
        return 1;
    }

    SDL_Quit();
    std::cout << "SDL OK\n";
    return 0;
}
