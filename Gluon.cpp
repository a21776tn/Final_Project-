#include "Gluon.h"
#include <iostream>

// Default constructor
Gluon::Gluon() : Particle(0.0, 0.0, 1, four_momentum{0.0, 0.0, 0.0, 0.0}), colour("red"), anti_colour("anti-red") {}

// Parameterized constructor
Gluon::Gluon(const std::string& colour, const std::string& anti_colour, double mass, double charge, int spin, const four_momentum& fm)
    : Particle(mass, charge, spin, fm), colour(colour), anti_colour(anti_colour) {}

// Copy constructor
Gluon::Gluon(const Gluon& other) : Particle(other), colour(other.colour), anti_colour(other.anti_colour) {}

// Copy assignment operator
Gluon& Gluon::operator=(const Gluon& other) {
    if (this != &other) {
        Particle::operator=(other);
        colour = other.colour;
        anti_colour = other.anti_colour;
    }
    return *this;
}

// Destructor
Gluon::~Gluon() {}

// Setter methods
void Gluon::set_color(const std::string& color) {
    this->colour = color;
}

void Gluon::set_antiColor(const std::string& antiColor) {
    this->anti_colour = antiColor;
}

// Getter methods
std::string Gluon::get_color() const {
    return colour;
}

std::string Gluon::get_antiColor() const {
    return anti_colour;
}

// Print information about the Gluon
void Gluon::print_info() const {
    std::cout << "Gluon Info:" << std::endl;
    std::cout << "Colour: " << colour << ", Anti-colour: " << anti_colour << std::endl;
    Particle::print_info();
    std::cout << std::endl;
}