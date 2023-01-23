// Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
        public:
            enum Mode {RECT, POL};
        // RECT for rectangular, POL for Polar modes
        private:
            double x; // horizontal value
            double y; // vertical value
            double mag; // length of vector
            double ang; // direction of vector in degrees
            Mode mode; // RECT or POL
        // private methods for setting values
            void set_mag();
            void set_ang();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval() const {return x;} // report x value
            double yval() const {return y;} // report y value
            double magval() const {return mag;} // report magnitude
            double angval() const {return ang;} // report angle
            void polar_mode();
            void rect_mode();
        // operator overloading
            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const; // 只有本身这个对象一个参数
            Vector operator*(double n) const;
        // friends
            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
};
#endif