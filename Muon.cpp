#include "Muon.h"

Muon::Muon() : Lepton(0.511, -1.0, 0.5, four_momentum(0.0, 0.0, 0.0, 0.511), 1), isolation_status(false) {}

Muon::Muon(double mass, double q, double spin, const four_momentum& p, int ln, bool isolated)
    : Lepton(mass, q, spin, p, ln), isolation_status(isolated) {}

Muon::~Muon() {}

void Muon::set_isolation_status(bool isolation_input) {isolation_status = isolation_input;}

bool Muon::get_isolation_status() const {return isolation_status;}

void Muon::print_info() const 
{
    if (charge > 0) {
        std::cout << "Anti Muon Info - ";
    } else if (charge < 0) {
        std::cout << "Muon Info - ";
    }
    std::cout<<std::endl;
    Particle::print_info();
    std::cout << "Isolation Status: " << (isolation_status ? "Isolated" : "Not Isolated") << std::endl;
    print_four_momentum();
    std::cout << std::endl;
}