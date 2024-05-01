#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "four_momentum.h"

class Particle 
{
protected:
    double rest_mass;
    double charge;
    double spin;
    std::unique_ptr<four_momentum> four_momentum_vector;

public:
    Particle();
    Particle(double m, double c, double s, const four_momentum& fm);
    Particle(const Particle& other);
    Particle& operator=(const Particle& other);
    virtual ~Particle();

    double get_spin() const;
    double get_charge() const;
    double get_rest_mass() const;
    const four_momentum& get_four_momentum() const;

    virtual void flip_charge();
    virtual void check_mass_consistency() const;
    virtual void print_four_momentum() const;
    virtual void print_info() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Particle& p);
};
