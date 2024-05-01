#pragma once
#include <vector>
#include "Lepton.h" // Include the base class header

// Electron derived class
class Electron : public Lepton 
{
protected:
    std::vector<double> electron_deposited_energies;

public:
    // Default constructor
    Electron();

    // Constructor for declaration with specific deposited energies 
    Electron(double mass, double q, double s, const four_momentum& p, int ln, const std::vector<double>& deposited_energies);
    
    virtual ~Electron();

    void check_energy();
    void set_EM_1(double energy);
    void set_EM_2(double energy);
    void set_HAD_1(double energy);
    void set_HAD_2(double energy);

    double get_EM_1() const;
    double get_EM_2() const;
    double get_HAD_1() const;
    double get_HAD_2() const;

    void print_deposited_energies() const;
    void print_info() const override; // Overridden from lepton class
};