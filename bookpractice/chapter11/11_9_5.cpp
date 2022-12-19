// Stonewt methods
#include "11_9_5.h"
using std::cout;

// private methods
void Stonewt::set_stone()
{
    stone = int(dpounds) / Lbs_per_stn;
    pds_left = int(dpounds) % Lbs_per_stn + dpounds - int(dpounds);
}

void Stonewt::set_ipounds()
{
    ipounds = int(dpounds);
}

void Stonewt::set_dpounds()
{
    dpounds = stone * Lbs_per_stn + pds_left;
}

// construct Stonewt object
Stonewt::Stonewt() // default constructor
{
    stone = pds_left = dpounds = ipounds = 0;
}

Stonewt::Stonewt(double n, Mode form)
{
    mode = form;
    if (form == STONE)
    {
        dpounds = n;
        set_stone();
    }
    else if (form == INT_POUNDS)
    {
        dpounds = n;
        set_ipounds();
    }
    else if (form == FLOAT_POUNDS)
    {
        dpounds = n;
    }
    else 
    {
        cout << "Incorrect 3rd argument to Stonewt() -- ";
        cout << "stonewt set to \n";
        stone = pds_left = dpounds = ipounds = 0;
        mode = FLOAT_POUNDS;
    }
}

void Stonewt::reset(double n, Mode form)
{
    mode = form;
    if (form == STONE)
    {
        dpounds = n;
        set_stone();
    }
    else if (form == INT_POUNDS)
    {
        dpounds = n;
        set_ipounds();
    }
    else if (form == FLOAT_POUNDS)
    {
        dpounds = n;
    }
    else 
    {
        cout << "Incorrect 3rd argument to Stonewt() -- ";
        cout << "stonewt set to \n";
        stone = pds_left = dpounds = ipounds = 0;
        mode = FLOAT_POUNDS;
    }
}

void Stonewt::stone_mode()
{
    mode = STONE;
}

void Stonewt::ipounds_mode()
{
    mode = INT_POUNDS;
}

void Stonewt::fpounds_mode()
{
    mode = FLOAT_POUNDS;
}

Stonewt::~Stonewt()
{

}

// operator
Stonewt Stonewt::operator+(const Stonewt & s) const
{
    return Stonewt(dpounds+s.dpounds);
}

Stonewt Stonewt::operator-(const Stonewt & s) const
{
    return Stonewt(dpounds - s.dpounds);
}

Stonewt Stonewt::operator-() const
{
    return Stonewt(-dpounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(dpounds * n);
}

Stonewt operator*(double n, const Stonewt & s)
{
    return s * n;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.mode == Stonewt::STONE)
    {
        os << "stone = " << s.stone << ", pds_left = " << s.pds_left;
    }
    else if (s.mode == Stonewt::INT_POUNDS)
    {
        os << "ipounds == " << s.ipounds;
    }
    else if (s.mode == Stonewt::FLOAT_POUNDS)
    {
        os << "dpounds = " << s.dpounds;
    }
    else
    {
        os << "Stonewt object mode is invalid";
    }
    return os;
}


// friends