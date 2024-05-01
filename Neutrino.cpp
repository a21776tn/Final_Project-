#include "Neutrino.h"
#include <iostream>

Neutrino::Neutrino() 
    : Lepton(0.0, 0.0, 0.5, four_momentum(0.0, 0.0, 0.0, 0.0), 1), type(neutrino_type::electron), has_interacted(false) {}

Neutrino::Neutrino(neutrino_type t, double m, double c, double s, const four_momentum& p, int ln, bool interacted)
    : Lepton(m, c, s, p, ln), type(t), has_interacted(interacted) {}

Neutrino::~Neutrino() {}

void Neutrino::set_neutrino_type(neutrino_type new_type) {
    type = new_type;
}

//Getters
neutrino_type Neutrino::get_neutrino_type() const {return type;}
bool Neutrino::get_neutrino_interaction_status() const {return has_interacted;}

//Setters
void Neutrino::set_neutrino_interaction_status(bool interaction_input) {has_interacted = interaction_input;}

//Print function for neutrinos
void Neutrino::print_info() const 
{
    std::string neutrino_type_name;
    switch (type) 
    {
        case neutrino_type::electron:
            neutrino_type_name = "Electron Neutrino";
            break;
        case neutrino_type::muon:
            neutrino_type_name = "Muon Neutrino";
            break;
        case neutrino_type::tau:
            neutrino_type_name = "Tau Neutrino";
            break;
    }

    std::cout << neutrino_type_name << " Information - ";
    std::cout << std::endl;
    Lepton::print_info();
    if(has_interacted) {std::cout << "Interaction Status: Has interacted" << std::endl;} 
    
    else {std::cout << "Interaction Status: Has not interacted" << std::endl;}

    std::cout << std::endl;
}