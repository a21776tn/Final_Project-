#pragma once
#include "Particle.h"

enum class quark_type { up, down, strange, charm, bottom, top };
class Quark : public Particle 
{
private:
    int quark_number;
    std::string colour_charge;
    quark_type type;

public:
    Quark();
    Quark(quark_type t, double m, double c, double s, const four_momentum& fm, int qn, std::string colour);
    Quark(const Quark& other);
    Quark& operator=(const Quark& other);
    ~Quark();

    void set_quark_number(int q_num);
    void set_colour_charge(const std::string& color);
    void set_type(quark_type t);

    int get_quark_number() const;
    std::string get_colour_charge() const;
    quark_type get_type() const;

    virtual void print_info() const override; // Override the pure virtual function from Particle
};