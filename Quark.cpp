#include "Quark.h"

Quark::Quark() : Particle(), quark_number(0), colour_charge("neutral"), type(quark_type::up) {}

//Parametrised Constructor
Quark::Quark(quark_type t, double m, double c, double s, const four_momentum& fm, int qn, std::string colour)
    : Particle(m, c, s, fm), quark_number(qn), colour_charge(colour), type(t) {}

Quark::Quark(const Quark& other)
    : Particle(other), quark_number(other.quark_number), colour_charge(other.colour_charge), type(other.type) {}

Quark& Quark::operator=(const Quark& other) 
{
    Particle::operator=(other);
    if (this != &other) 
    {
        quark_number = other.quark_number;
        colour_charge = other.colour_charge;
        type = other.type;
    }
    return *this;
}

Quark::~Quark() {}

//Setter functions
void Quark::set_type(quark_type t) {type = t;}
void Quark::set_colour_charge(const std::string& color) {colour_charge = color;}
void Quark::set_quark_number(int q_num) {quark_number = q_num;}

//Getter functions
std::string Quark::get_colour_charge() const {return colour_charge;}
int Quark::get_quark_number() const {return quark_number;}
quark_type Quark::get_type() const {return type;}

void Quark::print_info() const 
{
    std::string type_name;
    switch (type) {
        case quark_type::up:
            type_name = "Up";
            break;
        case quark_type::down:
            type_name = "Down";
            break;
        case quark_type::strange:
            type_name = "Strange";
            break;
        case quark_type::charm:
            type_name = "Charm";
            break;
        case quark_type::bottom:
            type_name = "Bottom";
            break;
        case quark_type::top:
            type_name = "Top";
            break;
    }

    std::cout << type_name << " Quark Information - " << std::endl;
    std::cout << "Quark Number: " << get_quark_number() << std::endl;
    std::cout << "Colour Charge: ";
    if (get_charge() > 0) {std::cout << "anti";}
    
    std::cout << get_colour_charge() << std::endl;
    Particle::print_info();
    std::cout<<std::endl;
}