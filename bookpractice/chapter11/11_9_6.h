// definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
    public:
        enum Mode {STONES, POUNDS}; // 这行必须写在Mode mode之前，不然写方法的时候会报错：不能将类型的值分配到类型的实体
    private:
        enum {Lbs_per_stn = 14}; // pounds per stone
        int stone; // whole stones
        double pds_left; // fractional pounds
        double pounds; // entire weight in pounds
        //Mode mode; // STONES or POUNDS
    public:
        Stonewt(double lbs); // constructor for double pounds
        Stonewt(int stn, double lbs); // constructor for stone, lbs
        Stonewt(); // default constructor
        ~Stonewt();
        // operators
        bool operator<(const Stonewt & s) const;
        bool operator>(const Stonewt & s) const;
        bool operator==(const Stonewt & s) const;
        bool operator<=(const Stonewt & s) const;
        bool operator>=(const Stonewt & s) const;
        bool operator!=(const Stonewt & s) const;
        // friends
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#endif