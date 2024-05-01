#pragma once
#include <iostream>
#include <string>
#include <cmath>

// Forward declaration for friend functions
class four_momentum;

class four_momentum 
{
private:
    double E;
    double px;
    double py;
    double pz;

public:
    // Parametrised constructor
    four_momentum(double E, double px, double py, double pz);

    // Destructor
    ~four_momentum();

    // Copy and move semantics
    four_momentum(const four_momentum& other);
    four_momentum& operator=(const four_momentum& other);
    four_momentum(four_momentum&& other) noexcept;
    four_momentum& operator=(four_momentum&& other) noexcept;

    // Friend functions
    friend four_momentum operator+(const four_momentum& a, const four_momentum& b);
    friend double dotProduct(const four_momentum& a, const four_momentum& b);

    // Setter functions
    void set_E(double E);
    void set_px(double px);
    void set_py(double py);
    void set_pz(double pz);

    // Getter functions
    double get_E() const;
    double get_px() const;
    double get_py() const;
    double get_pz() const;
    double get_p() const;
    double get_invariant_mass() const;

    // Utility functions
    void check_consistency();
    void check_E();
    void print_four_momentum() const;

};