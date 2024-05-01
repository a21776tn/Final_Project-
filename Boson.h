#pragma once
#include "Particle.h"
#include <iostream>

class Boson : public Particle {

public:
    // Default constructor
    Boson();

    // Parametrized constructor
    Boson(double m, double c, int s, const four_momentum& fm);

    // Copy constructor
    Boson(const Boson& other);

    // Assignment operator
    Boson& operator=(const Boson& other);

    // Destructor
    virtual ~Boson();

    // Member functions
    void print_info() const;
};