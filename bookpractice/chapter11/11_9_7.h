// definition of the complex class
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class complex
{
    private:
        double real; // real number
        double imaginary; // imaginary number
    public:
        complex(); // default constructor
        complex(double realnum, double imaginarynum);
        ~complex();
        complex operator+(const complex & c) const;
        complex operator-(const complex & c) const;
        complex operator*(const complex & c) const;
        complex operator*(double n) const;
        complex operator~() const;

    // friends
        friend complex operator*(double n, const complex & c);
        friend std::ostream & operator<<(std::ostream & os, const complex & c);
        friend std::istream & operator>>(std::istream & in, complex & c);
};

#endif