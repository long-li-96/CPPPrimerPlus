#include "13_11_4.h"
#include <cstring>

// Port methods
Port::Port(const char * br, const char * st, int b):
bottles(b)
{
    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);
    std::strncpy(style, st, 19);
    style[19] = '\0';
}

Port::Port(const Port & p)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == & p)
        return * this;
    delete [] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
    return * this;
}

Port & Port::operator+=(int b)
{
    if (b < 0)
        b = 0;
    bottles += b;
    return * this;
}

Port & Port::operator-=(int b)
{
    if (b > bottles)
        b = bottles;
    bottles -= b;
    return * this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// VintagePort methods
VintagePort::VintagePort(): Port()
{
    nickname = new char[5];
    std::strcpy(nickname, "none");
    nickname[4] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y):
Port(br, "none", b)
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp): Port(vp)
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == & vp)
        return * this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return * this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (const Port &) vp;
    cout << ", " << vp.nickname << ", " << vp.year;
    return os;
}