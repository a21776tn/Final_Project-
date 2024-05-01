#include "Tau.h"
#include <iostream>

// Default constructor definition (if needed)
Tau::Tau(double mass, double charge, double spin, const four_momentum& p, int ln)
    : Lepton(mass, charge, spin, p, ln) {}

// Constructor for any decay particles
Tau::Tau(double mass, double charge, double spin, const four_momentum& p, int ln, std::vector<std::shared_ptr<Particle>> decayProducts)
    : Lepton(mass, charge, spin, p, ln), decayedParticles(decayProducts) {
    check_charge_consistency();
}

Tau::~Tau() {}

void Tau::check_charge_consistency() const {
    double chargeSum = 0.0;
    double tolerance = 1e-2;

    for (const auto& particle : decayedParticles) {
        chargeSum += particle->get_charge();
    }

    if (std::abs(chargeSum - this->get_charge()) > tolerance) {
        std::cout<<"Charge conservation violated in tau decay."<<std::endl;
    }
}

void Tau::print_info() const 
{

    std::cout << "Tau Information - " << std::endl;
    Lepton::print_info();

        int count = 1;
        for (const auto& decayedParticle : decayedParticles) 
        {
            if (decayedParticle) {
                std::cout << "Decayed Particle " << count << ": ";
                std::cout << std::endl;
                decayedParticle->print_info();
                std::cout << std::endl;
            }
            ++count;
        }
};