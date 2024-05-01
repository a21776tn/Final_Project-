#pragma once
#include "Lepton.h"

enum class neutrino_type { electron, muon, tau };

class Neutrino : public Lepton {
private:
    neutrino_type type;
    bool has_interacted;

public:
    Neutrino(); // Default constructor should set a default type
    Neutrino(neutrino_type type, double m, double c, double s, const four_momentum& p, int ln, bool interacted);
    virtual ~Neutrino() override;

    void set_neutrino_type(neutrino_type new_type);
    neutrino_type get_neutrino_type() const;
    void set_neutrino_interaction_status(bool interaction_input);
    bool get_neutrino_interaction_status() const;

    void print_info() const override;
};