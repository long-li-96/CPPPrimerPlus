// definiton for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
    public:
        enum Mode {STONE, INT_POUNDS, FLOAT_POUNDS};
    private:
        enum {Lbs_per_stn = 14}; // pounds per stone
        int stone; // whole stones
        double pds_left; // fractional pounds
        double dpounds; // entire weight in pounds
        int ipounds;
        Mode mode;
        // private methods for setting values
        void set_stone();
        void set_ipounds();
        void set_dpounds();
    public:
        Stonewt(); // default constructor
        Stonewt(double n, Mode form = FLOAT_POUNDS);
        void reset(double n, Mode form = FLOAT_POUNDS);
        int stoneval() const {return stone;} // report stone value
        double pds_left_val() const {return pds_left;} // report pds_left value
        double dpoundsval() const {return dpounds;} // report dpounds value
        int ipoundsval() const {return ipounds;} // report ipounds value
        void stone_mode();
        void ipounds_mode();
        void fpounds_mode();
        // Stonewt(double lbs); // constructor for double pounds
        // Stonewt(int stn, double lbs); // constructor for stone, lbs
        ~Stonewt();
        // void show_lbs() const; // show weight in pounds format
        // void show_stn() const; // show weight in stone format
        Stonewt operator+(const Stonewt & s) const;
        Stonewt operator-(const Stonewt & s) const;
        Stonewt operator-() const;
        Stonewt operator*(double n) const;
        
    // friends
        friend Stonewt operator*(double n, const Stonewt & s);
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};
#endif