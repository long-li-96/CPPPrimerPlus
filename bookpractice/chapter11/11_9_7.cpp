// complex methods
#include "11_9_7.h"
using std::cout;

// public member methods
complex::complex()
{
    real = 0.0;
    imaginary = 0.0;
}

complex::complex(double realnum, double imaginarynum)
{
    real = realnum;
    imaginary = imaginarynum;
}

complex::~complex()
{

}

complex complex::operator+(const complex & c) const
{
    complex com;
    com.real = real + c.real;
    com.imaginary = imaginary + c.imaginary;
    return com;
}

complex complex::operator-(const complex & c) const
{
    complex com;
    com.real = real - c.real;
    com.imaginary = imaginary - c.imaginary;
    return com;
}

complex complex::operator*(const complex & c) const
{
    complex com;
    com.real = real * c.real - imaginary * c.imaginary;
    com.imaginary = real * c.imaginary + imaginary * c.real;
    return com;
}

complex complex::operator*(double n) const
{
    complex com;
    com.real = real * n;
    com.imaginary = imaginary * n;
    return com;
}

complex complex::operator~() const
{
    complex com;
    com.real = real;
    com.imaginary = - com.imaginary;
    return com;
}

// friends
complex operator*(double n, const complex & c)
{
    return c * n;
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream & in, complex & c)
{
    cout << "real: ";
    in >> c.real;
    cout << "imaginal: ";
    in >> c.imaginary;
    return in;
}