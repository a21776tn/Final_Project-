#include <iostream>
#include <vector>
#include <memory>
#include "Quark.cpp"
#include "Particle.cpp"
#include "Lepton.cpp"
#include "Muon.cpp"
#include "Neutrino.cpp"
#include "Electron.cpp"
#include "physical_constants.h"
#include "DecayingParticle.h" 
#include "Boson.cpp"
#include "Gluon.cpp"
#include "four_momentum.cpp"
#include "Tau.cpp"
#include "ParticleContainer.cpp"


int main() 
{
    // Container
    ParticleContainer container;

    // Adding particles to the container
    auto muonPtr = std::make_shared<Muon>(muon_rest_mass, electron_charge, fermion_spin, four_momentum(1, 0, 0, 0), 1, false);
    container.push_particle_back(muonPtr);

    auto electronPtr = std::make_shared<Electron>(electron_rest_mass, electron_charge, fermion_spin, four_momentum(30, 2, 3, 4), 1, std::vector<double>{10, 10, 5, 5});
    container.push_particle_back(electronPtr);

    auto muonNeutrinoPtr = std::make_shared<Neutrino>(neutrino_type::muon, -electron_charge, 3.0, fermion_spin, four_momentum(1, 0, 0, 0), 1, false);
    container.push_particle_back(muonNeutrinoPtr);

    auto electronNeutrinoPtr = std::make_shared<Neutrino>(neutrino_type::electron, 0.0, 3.0, fermion_spin, four_momentum(1, 0, 0, 0), 1, false);
    container.push_particle_back(electronNeutrinoPtr);

    auto tauNeutrinoPtr = std::make_shared<Neutrino>(neutrino_type::tau, 0.0, 3.0, fermion_spin, four_momentum(1, 0, 0, 0), 1, false);
    container.push_particle_back(tauNeutrinoPtr);

    auto tauPtr = std::make_shared<Tau>(electron_rest_mass, electron_charge, fermion_spin, four_momentum(30, 2, 3, 4), 1, std::vector<std::shared_ptr<Particle>>
    {muonPtr, electronPtr, muonNeutrinoPtr});
    container.push_particle_back(tauPtr);

    auto gluonPtr = std::make_shared<Gluon>("red", "anti-red", 0.0, 0.0, 1, four_momentum{10, 0.0, 0.0, 0.0});
    container.push_particle_back(gluonPtr);

    auto photonPtr = std::make_shared<Boson>(0.0, 0.0, 1, four_momentum{10, 0.0, 0.0, 0.0});
    container.push_particle_back(gluonPtr);

    auto W_boson_ptr = std::make_shared<DecayingParticle<Muon, Electron>>(80.379, electron_charge, 1.0, four_momentum{1000, 0.0, 0.0, 80.379}, muonPtr, electronPtr);
    container.push_particle_back(W_boson_ptr);

    auto Z_boson_ptr = std::make_shared<DecayingParticle<Muon, Electron>>(80.379, 0, 1.0, four_momentum{1000, 0.0, 0.0, 80.379}, muonPtr, electronPtr);
    container.push_particle_back(Z_boson_ptr);

    auto Higgs_boson_ptr = std::make_shared<DecayingParticle<Muon, Electron>>(80.379, 0, 0, four_momentum{1000, 0.0, 0.0, 80.379}, muonPtr, electronPtr);
    container.push_particle_back(Higgs_boson_ptr);

    auto up_quarkPtr = std::make_shared<Quark>(quark_type::up, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(up_quarkPtr);

    auto down_quarkPtr = std::make_shared<Quark>(quark_type::down, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(down_quarkPtr);

    auto charm_quarkPtr = std::make_shared<Quark>(quark_type::charm, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(charm_quarkPtr);

    auto starnge_quarkPtr = std::make_shared<Quark>(quark_type::strange, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(starnge_quarkPtr);

    auto top_quarkPtr = std::make_shared<Quark>(quark_type::top, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(top_quarkPtr);

    auto bottom_quarkPtr = std::make_shared<Quark>(quark_type::bottom, 2.3, 2/3.0, 0.5, four_momentum(10, 0, 0, 2.3), 1, "red");
    container.push_particle_back(bottom_quarkPtr);

    auto quarkSubContainer = container.get_sub_container(std::type_index(typeid(Quark)));
    quarkSubContainer.print_info();

    auto leptonSubContainer = container.get_sub_container(std::type_index(typeid(Lepton)));
    leptonSubContainer.print_info();

    auto bosonSubContainer = container.get_sub_container(std::type_index(typeid(Boson)));
    bosonSubContainer.print_info();

    container.get_total_number_of_particles();

    return 0;
}