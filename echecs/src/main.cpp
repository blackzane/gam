#include <iostream>
#include "Application.hpp"

int main(int argc, char* argv[]) {
    try {
        Application app;
        app.executer();
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
