#ifndef APP_HPP
#define APP_HPP

#include "Core/Plateau.hpp"
#include "GUI.hpp"

class Application {
private:
    Plateau plateau;
    InterfaceGraphique interfaceGraphique;
    bool applicationEnCours;

public:
    Application();
    void executer();
};

#endif
