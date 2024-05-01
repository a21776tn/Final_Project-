#include "ParticleContainer.h"
#include <iostream>
#include <algorithm>

void ParticleContainer::push_particle_back(const std::shared_ptr<Particle>& particle) 
{
    std::type_index type_index(typeid(*particle));
    particles[type_index].push_back(particle);
}

size_t ParticleContainer::get_total_number_of_particles() const 
{
    size_t total = 0;
    for (const auto& pair : particles) 
    {
        total += pair.second.size();
    }
    std::cout << "Total number of particles: " << total << std::endl;
    return total;
}

std::map<std::type_index, size_t> ParticleContainer::get_number_of_particles_by_type() const 
{
    std::map<std::type_index, size_t> count_by_type;
    for (const auto& pair : particles) 
    {
        count_by_type[pair.first] = pair.second.size();
    }
    return count_by_type;
}

// four_momentum ParticleContainer::sum_four_momentum() const 
// {
//     four_momentum total(0, 0, 0, 0); 

//     // Loop through each particle type
//     for (const auto& pair : particles) {
//         // Loop through each particle of a type
//         for (const auto& particle_ptr : pair.second) {
//             if (particle_ptr) {
//                 // Dereference the shared pointer and sum the four-momenta
//                 total += particle_ptr->get_four_momentum();
//             }
//         }
//     }
//     return total; // Return the total four-momentum
//}

ParticleContainer ParticleContainer::get_sub_container(std::type_index type) const 
{
    ParticleContainer sub_container;
    auto found = particles.find(type);
    if (found != particles.end()) {
        sub_container.particles[type] = found->second;
    }
    return sub_container;
}

void ParticleContainer::print_info() const 
{
    for (const auto& pair : particles) {
        for (const auto& particle : pair.second) {
            particle->print_info();
        }
    }
}