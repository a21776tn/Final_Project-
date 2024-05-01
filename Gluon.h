#pragma once
#include "Particle.h"
#include <string>

class Gluon : public Particle {
private:
    std::string colour;      // Color charge of the gluon
    std::string anti_colour;  // Anti-color charge of the gluon

public:
    // Default constructor
    Gluon();

    // Parameterized constructor
    Gluon(const std::string& colour, const std::string& anti_colour, double mass, double charge, int spin, const four_momentum& fm);

    // Copy constructor
    Gluon(const Gluon& other);

    // Copy assignment operator
    Gluon& operator=(const Gluon& other);

    // Destructor
    virtual ~Gluon();

    // Setters
    void set_color(const std::string& colour);
    void set_antiColor(const std::string& anti_colour);

    // Getters
    std::string get_color() const;
    std::string get_antiColor() const;

    // Print information specific to gluon
    virtual void print_info() const override;
};