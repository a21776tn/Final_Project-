#include "Lepton.h"

Lepton::Lepton() : Particle(), lepton_number(0) {}

Lepton::Lepton(double m, double c, double s, const four_momentum& fm, int ln) :
    Particle(m, c, s, fm), lepton_number(ln) {}

Lepton::Lepton(const Lepton& other) :
    Particle(other), lepton_number(other.lepton_number) {}

Lepton& Lepton::operator=(const Lepton& other) 
{
    Particle::operator=(other);
    if (this != &other) {lepton_number = other.lepton_number;}
    return *this;
}

Lepton::~Lepton() {}

void Lepton::print_info() const 
{
    std::cout << "Lepton Number: " << lepton_number << std::endl;
    Particle::print_info();
}

int Lepton::get_lepton_number() const {return lepton_number;}

void Lepton::set_lepton_number(int ln) {lepton_number = ln;}
