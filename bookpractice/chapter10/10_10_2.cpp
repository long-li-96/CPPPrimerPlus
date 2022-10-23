// implementing the Person class
#include <iostream>
#include <cstring>
#include "10_10_2.h"

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
    //std::cout << "Person()";
    //std::cout << "lname: " << "\n" <<  lname << "fname: " << fname << std::endl;
}

void Person::Show() const 
{
    std::cout << fname << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << lname << fname << std::endl;
}