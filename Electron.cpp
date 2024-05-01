#include "Electron.h"
#include <iostream>
#include <stdexcept>
#include <numeric>

Electron::Electron() : Lepton(0.511, -1.0, 0.5, four_momentum(0.0, 0.0, 0.0, 0.511), 1), electron_deposited_energies({0.0, 0.0, 0.0, 0.0}) {}

Electron::Electron(double mass, double q, double s, const four_momentum& p, int ln, const std::vector<double>& deposited_energies) : Lepton(mass, q, s, p, ln), electron_deposited_energies(deposited_energies) 
{
    if (deposited_energies.size() != 4) 
    {
        throw std::invalid_argument("Deposited energies vector must have exactly 4 elements.");
    }
    check_energy();
}

Electron::~Electron() {std::cout << "electron destructor called" << std::endl;}

void Electron::check_energy() 
{
    double four_momentum_energy = this->four_momentum_vector->get_E();
    double total_electron_energies = std::accumulate(electron_deposited_energies.begin(), electron_deposited_energies.end(), 0.0);

    if (total_electron_energies != four_momentum_energy) {
        throw std::invalid_argument("Total electron deposited energies must equal the electron's total energy.");
    }
}

void Electron::set_EM_1(double energy) { electron_deposited_energies[0] = energy; }
void Electron::set_EM_2(double energy) { electron_deposited_energies[1] = energy; }
void Electron::set_HAD_1(double energy) { electron_deposited_energies[2] = energy; }
void Electron::set_HAD_2(double energy) { electron_deposited_energies[3] = energy; }

double Electron::get_EM_1() const { return electron_deposited_energies[0]; }
double Electron::get_EM_2() const { return electron_deposited_energies[1]; }
double Electron::get_HAD_1() const { return electron_deposited_energies[2]; }
double Electron::get_HAD_2() const { return electron_deposited_energies[3]; }

void Electron::print_deposited_energies() const 
{
    std::cout << "Deposited Energies: [EM1: " << electron_deposited_energies[0] 
              << ", EM2: " << electron_deposited_energies[1] 
              << ", HAD1: " << electron_deposited_energies[2] 
              << ", HAD2: " << electron_deposited_energies[3] << "]" << std::endl;
}

void Electron::print_info() const 
{
    if (charge > 0) { std::cout << "Anti Electron Info - "; }
    else if (charge < 0) { std::cout << "Electron Info - "; }
    std::cout<<std::endl; 
    print_deposited_energies();
    Particle::print_info();

    std::cout << std::endl;
}