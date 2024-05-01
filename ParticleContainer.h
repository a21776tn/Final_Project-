#pragma once
#include "Particle.h"
#include <map>
#include <vector>
#include <memory>
#include <typeindex>

// Container class for particles
class ParticleContainer 
{
private:
    std::map<std::type_index, std::vector<std::shared_ptr<Particle>>> particles;

public:
    void push_particle_back(const std::shared_ptr<Particle>& particle);
    size_t get_total_number_of_particles() const;
    std::map<std::type_index, size_t> get_number_of_particles_by_type() const;
    four_momentum sum_four_momentum() const;
    ParticleContainer get_sub_container(std::type_index type) const;
    void print_info() const;
};