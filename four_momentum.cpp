#include "four_momentum.h"

// Constructor
four_momentum::four_momentum(double E, double px, double py, double pz) : E(E), px(px), py(py), pz(pz) {check_consistency();}

// Destructor
four_momentum::~four_momentum() {}

// Copy constructor
four_momentum::four_momentum(const four_momentum& other) : E(other.E), px(other.px), py(other.py), pz(other.pz) 
{std::cout << "Calling Copy Constructor\n";}

// Copy assignment
four_momentum& four_momentum::operator=(const four_momentum& other) 
{
    std::cout << "Calling Copy Assignment Operator\n";
    if (this != &other) {
        E = other.E;
        px = other.px;
        py = other.py;
        pz = other.pz;
    }
    return *this;
}

// Move constructor
four_momentum::four_momentum(four_momentum&& other) noexcept
    : E(std::move(other.E)), px(std::move(other.px)), py(std::move(other.py)), pz(std::move(other.pz)) 
    {std::cout << "Calling Move Constructor\n";}

// Move assignmentoperator
four_momentum& four_momentum::operator=(four_momentum&& other) noexcept 
{
    std::cout << "Calling Move Assignment Operator\n";
    if (this != &other) {
        E = std::move(other.E);
        px = std::move(other.px);
        py = std::move(other.py);
        pz = std::move(other.pz);
    }
    return *this;
}

//Check physical consistency
void four_momentum::check_consistency() 
{
    const double EPSILON = 1e-2;  // Epsilon value for comparison
    double p_squared = px * px + py * py + pz * pz;
    double m_squared = this->get_invariant_mass() * this->get_invariant_mass();
    double E_squared = E * E;

    if (E < 0)
        throw std::invalid_argument("Energy cannot be negative.");

    if (E < sqrt(p_squared))  // Causality check: particle velocity must be smaller than the speed of light
        throw std::invalid_argument("Violation of causality: E is less than the magnitude of momentum.");

    if (std::fabs(E_squared - (p_squared + m_squared)) > EPSILON)
        std::cerr << "Warning: The energy-momentum relation does not hold within the tolerance.\n";
}

//Setters
void four_momentum::set_px(double px) { this->px = px; }
void four_momentum::set_py(double py) { this->py = py; }
void four_momentum::set_pz(double pz) { this->pz = pz; }

//Getters 
double four_momentum::get_E() const { return E; }
double four_momentum::get_px() const { return px; }
double four_momentum::get_py() const { return py; }
double four_momentum::get_pz() const { return pz; }
double four_momentum::get_p() const { return sqrt(px * px + py * py + pz * pz); }
double four_momentum::get_invariant_mass() const { return sqrt(E*E - px*px - py*py - pz*pz); }

//Print function
void four_momentum::print_four_momentum() const 
{
    std::cout << "Four Momentum: [E: " << E << ", px: " << px << ", py: " << py << ", pz: " << pz << "]" << std::endl;
}

//Overload addition operator
four_momentum operator+(const four_momentum& a, const four_momentum& b) 
{
    return four_momentum(a.get_E() + b.get_E(), a.get_px() + b.get_px(), a.get_py() + b.get_py(), a.get_pz() + b.get_pz());
}

//overloaded dot product operator
double dotProduct(const four_momentum& a, const four_momentum& b) 
{
    return a.get_E() * b.get_E() + a.get_px() * b.get_px() + a.get_py() * b.get_py() + a.get_pz() * b.get_pz();
}