#pragma once
#include "Boson.h"
#include "Particle.h"
#include <iostream>
#include <memory>

template <typename T1, typename T2>
class DecayingParticle : public Boson 
{
private:
    std::vector<std::shared_ptr<Particle>> decayedParticles;

public:
    // Constructors
    DecayingParticle() : Boson(0.0, 0.0, 0.0, four_momentum{0, 0, 0, 0}) {} // Default constructor

    //Parametrised constructor for two particle decay (bosonic decay)
    DecayingParticle(double mass, double charge, double spin, const four_momentum& p, std::shared_ptr<T1> particle1, std::shared_ptr<T2> particle2)
        : Boson(mass, charge, spin, p) {
        decayedParticles.push_back(particle1);
        decayedParticles.push_back(particle2);
        check_charge_conservation();
    }
    
    // Destructor
    virtual ~DecayingParticle() {}

    void check_charge_conservation() const {
        double initial_charge = this->get_charge();
        double total_decayed_charge = 0;

        for (const auto& particle : decayedParticles) 
        {
            if (particle) 
            {
                total_decayed_charge += particle->get_charge();
            }
        }

        // Check for charge conservation
        if (initial_charge != total_decayed_charge) 
        {
            std::cerr << "Charge conservation violation: Initial charge (" 
                      << initial_charge << ") does not equal total decayed charge (" 
                      << total_decayed_charge << ")." << std::endl;
        }
    }

    // Member function to print particle information
    void print_info() const
    {
        // Use conditions to determine the type of particle based on spin and charge
        double spin = this->get_spin();
        double charge = this->get_charge();

        if (spin == 1 && abs(charge) == 1) {std::cout << "W Boson Info:" << std::endl;}

        else if (spin == 1 && charge == 0) {std::cout << "Z Boson Info:" << std::endl;} 
        
        else if (spin == 0 && charge == 0) {std::cout << "Higgs Boson Info:" << std::endl;}
        
        else {std::cout << "Particle Info:" << std::endl;} // Default case for particles not matching the above criteria}

        std::cout<<std::endl;

        Particle::print_info(); // Call base class print_info() to print common particle info

        std::cout << std::endl;

        int count = 1;
        for (const auto& decayedParticle : decayedParticles) 
        {
            if (decayedParticle) 
            {
                std::cout << "Decayed Particle " << count << ": ";
                std::cout << std::endl;
                decayedParticle->print_info();
                std::cout << std::endl;
            }
            ++count;
        }
    }
    };