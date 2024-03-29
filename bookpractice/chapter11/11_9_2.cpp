// methods for the Vector class
#include <iostream>
#include <cmath>
#include "11_9_2.h"
using std::cout;
using std::sin;
using std::sqrt;
using std::cos;
using std::atan;
using std::atan2;

namespace VECTOR
{
    // compute degrees in one redian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods 
    // calculate magnitude from x and y
    // void Vector::set_mag()
    // {
    //     mag = sqrt(x * x + y * y);
    // }

    // void Vector::set_ang()
    // {
    //     if (x == 0.0 && y == 0.0)
    //         ang = 0.0;
    //     else
    //         ang = atan2(y, x);
    // }

    // set x from polar coordinate
    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    // set y from polar coordinate
    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }
    
    // public methods
    Vector::Vector() // default constructor
    {
        x = y = 0.0;
        mode = RECT;
    }

    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2/Rad_to_deg);
            set_y(n1, n2/Rad_to_deg);
        }
        else 
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    // reset vector from rectangular coordinates if form is 
    // RECT (the default) or else form polar coordinates if 
    // form is POL
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2/Rad_to_deg);
            set_y(n1, n2/Rad_to_deg); 
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector() // destructor
    {

    }

    double Vector::magval() const
    {
        double mag;
        mag = sqrt(x * x + y * y);
        return mag;
    }

    double Vector::angval() const
    {
        double ang;
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
        return ang; 
    }

    void Vector::polar_mode() // set to polar mode
    {
        mode = POL;
    }

    void Vector::rect_mode() // set to rectangular mode
    {
        mode = RECT;
    }

    // operator overloading
    // add two Vectors
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y );
    }

    // subtract Vector b from a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // multiply vector by n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // friend methods
    // multiply n by Vector a
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        }
        else 
            os << "Vector object mode is invalid";
        return os;
    }
} // end namespace VECTOR