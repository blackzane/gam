#ifndef REGLES_HPP
#define REGLES_HPP

#include "Plateau.hpp"
#include "Coup.hpp"

class Regles {
public:
    static bool coupValide(const Plateau& plateau, const Coup& coup);
};

#endif
