#include "Application.hpp"

Application::Application() : enCours(true) {}

void Application::executer() {
    interface.initialiser();

    while (enCours) {
        interface.evenements(enCours, plateau);
        interface.dessiner(plateau);
    }

    interface.nettoyer();
}
