#include "Boson.h"
#include <iostream>

// Constructors and destructors as previously defined
Boson::Boson() : Particle(0, 0, 0, four_momentum(0.0, 0.0, 0.0, 0.0)) {}

Boson::Boson(double m, double c, int s, const four_momentum& fm) : Particle(m, c, s, fm) {}

Boson::Boson(const Boson& other) : Particle(other) {}

Boson& Boson::operator=(const Boson& other) 
{
    if (this != &other) {Particle::operator=(other);}
    return *this;
}

void Boson::print_info() const
{
    if (get_spin() == 1 && get_charge() == 0 && get_rest_mass() == 0) {
        std::cout << "Photon Info:" << std::endl;
    }
    Particle::print_info();
    std::cout<<std::endl;
}

Boson::~Boson() {}