#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Core/Plateau.hpp"
#include "Interface.hpp"

class Application {
private:
    bool enCours;
    Plateau plateau;
    Interface interfaceJeu;

public:
    Application();
    void executer();
};

#endif
