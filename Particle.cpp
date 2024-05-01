#pragma once
#include "Particle.h"
#include <cmath>
#include <numeric>

Particle::Particle() : rest_mass(0.0), charge(0.0), spin(0.0), four_momentum_vector(nullptr) {}

Particle::Particle(double m, double c, double s, const four_momentum& fm) : 
    rest_mass(m), charge(c), spin(s), four_momentum_vector(std::make_unique<four_momentum>(fm)) {}

Particle::Particle(const Particle& other) : 
    rest_mass(other.rest_mass), charge(other.charge), spin(other.spin),
    four_momentum_vector(std::make_unique<four_momentum>(*other.four_momentum_vector)) {}

Particle& Particle::operator=(const Particle& other) 
{
    if (this != &other) 
    {
        rest_mass = other.rest_mass;
        charge = other.charge;
        spin = other.spin;
        four_momentum_vector = std::make_unique<four_momentum>(*other.four_momentum_vector);
    }
    return *this;
}

Particle::~Particle() {}

// Getter functions 
double Particle::get_spin() const {return spin;}
double Particle::get_charge() const {return charge;}
double Particle::get_rest_mass() const {return rest_mass;}
const four_momentum& Particle::get_four_momentum() const {return *four_momentum_vector;}

void Particle::flip_charge() {charge = -charge;}

void Particle::check_mass_consistency() const 
{
    if (four_momentum_vector) 
    {
        double invariant_mass = four_momentum_vector->get_invariant_mass();
        const double EPSILON = 1e-6;  // Small tolerance for floating point comparison

        if (std::fabs(invariant_mass - rest_mass) > EPSILON) {
            std::cerr << "Consistency Error: The invariant mass " << invariant_mass
                      << " does not match the particle's rest mass " << rest_mass << "." << std::endl;
        }
    }
}

void Particle::print_info() const
{
    std::cout << "Mass: " << get_rest_mass() << std::endl;
    std::cout << "Charge: " << get_charge() << std::endl;
    std::cout << "Spin: " << get_spin() << std::endl;
    std::cout << "Four-Momentum: (E: " << four_momentum_vector->get_E() 
              << ", px: " << four_momentum_vector->get_px()
              << ", py: " << four_momentum_vector->get_py() 
              << ", pz: " << four_momentum_vector->get_pz() << ")" << std::endl;
}

// Additiional print method specifically for four-momentum
void Particle::print_four_momentum() const 
{
    std::cout << "Four-Momentum: (E: " << four_momentum_vector->get_E() 
              << ", px: " << four_momentum_vector->get_px()
              << ", py: " << four_momentum_vector->get_py() 
              << ", pz: " << four_momentum_vector->get_pz() << ")" << std::endl;
}