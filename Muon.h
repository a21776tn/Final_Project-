#pragma once
#include <iostream>
#include "Lepton.h" // Include the base class header

// Muon derived class
class Muon : public Lepton 
{
protected:
    bool isolation_status;

public:
    // Default constructor
    Muon();

    // Parametrised constructor
    Muon(double mass, double q, double spin, const four_momentum& p, int ln, bool isolated);

    // Destructor
    ~Muon();

    // Setters and Getters
    void set_isolation_status(bool isolation_input);
    bool get_isolation_status() const;

    // Implementation of pure virtual function from base class
    void print_info() const override;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Muon& m);
};