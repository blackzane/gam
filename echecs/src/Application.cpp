#include "App.hpp"

Application::Application()
    : applicationEnCours(true)
{
    plateau.reinitialiser();
    interfaceGraphique.initialiser();
}

void Application::executer()
{
    while (applicationEnCours) {
        interfaceGraphique.gererEvenements(applicationEnCours, plateau);
        interfaceGraphique.dessiner(plateau);
    }

    interfaceGraphique.nettoyer();
}
