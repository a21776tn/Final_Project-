#pragma once
#include <memory>
#include <vector>
#include "Lepton.h"
#include "Quark.h"
#include "Neutrino.h"  // Assuming you have classes for Quarks and Neutrinos

class Tau : public Lepton {
protected:
    // Removed the decay_mode enum since we don't need a flag for decay type anymore
    std::vector<std::shared_ptr<Particle>> decayedParticles; // Now handles any decay particles

public:
    // Constructors
    Tau(double mass, double charge, double spin, const four_momentum& p, int ln);
    
    // Constructor for any decay particles, accepts a vector of particles
    Tau(double mass, double charge, double spin, const four_momentum& p, int ln, std::vector<std::shared_ptr<Particle>> decayProducts);

    // Destructor
    virtual ~Tau();

    // Consistency check for charge
    void check_charge_consistency() const;

    // Overridden virtual function to display tau information
    void print_info() const override;
};
