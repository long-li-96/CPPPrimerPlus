// Stonewt methods
#include "11_9_6.h"
using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0.0;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; //integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::~Stonewt() // destructor
{

}

// friend methods
std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    
    os << "pounds = " << s.pounds << std::endl;
    os << "(stone, pds_left) = " << "(" << s.stone
    << ", " << s.pds_left << ")" << std::endl;
    return os;
}

// operators
bool Stonewt::operator<(const Stonewt & s) const
{
    if (pounds < s.pounds)
        return true;
    else 
        return false;
}

bool Stonewt::operator>(const Stonewt & s) const
{
    if (pounds > s.pounds)
        return true;
    else 
        return false;
}

bool Stonewt::operator<=(const Stonewt & s) const
{
    if (pounds <= s.pounds)
        return true;
    else
        return false;
}

bool Stonewt::operator>=(const Stonewt & s) const
{
    if (pounds >= s.pounds)
        return true;
    else 
        return false;
}

bool Stonewt::operator==(const Stonewt & s) const
{
    if (pounds == s.pounds)
        return true;
    else
        return false;
}

bool Stonewt::operator!=(const Stonewt & s) const
{
    if (pounds != s.pounds)
        return true;
    else
        return false;
}
