#include <iostream>
#include <cstring>
#include "10_10_7.h"

Plorg::Plorg(const char * str, const int ci)
{
    strcpy(name, str);
    CI = ci;
}

void Plorg::resetCI(const int ci)
{
    CI = ci;
}

void Plorg::show() const
{
    std::cout << "The name is: " << name << std::endl;
    std::cout << "The CI is: " << CI << std::endl;
}