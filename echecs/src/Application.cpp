#include "Application.hpp"

Application::Application()
{
    enCours = true;
    plateau.initialiser();
    interfaceJeu.initialiser();
}

void Application::executer()
{
    while (enCours) {
        interfaceJeu.evenements(enCours, plateau);
        interfaceJeu.dessiner(plateau);
    }
    interfaceJeu.nettoyer();
}
