#pragma once

#include "Particle.h"
#include "physical_constants.h"

class Lepton : public Particle {
private:
    int lepton_number;

public:
    Lepton();
    Lepton(double m, double c, double s, const four_momentum& fm, int ln);
    Lepton(const Lepton& other);
    Lepton& operator=(const Lepton& other);
    Lepton(Lepton&& other) noexcept;
    Lepton& operator=(Lepton&& other) noexcept;

    virtual void print_info() const override;
    virtual ~Lepton();

    int get_lepton_number() const;
    void set_lepton_number(int ln);
};
