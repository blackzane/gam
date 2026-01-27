#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Interface.hpp"
#include "Core/Plateau.hpp"

class Application {
public:
    Application();
    void executer();

private:
    Interface interface;
    Plateau plateau;
    bool enCours;
};

#endif
