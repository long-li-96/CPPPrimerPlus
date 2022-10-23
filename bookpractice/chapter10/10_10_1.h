// class definition for the Bankaccount
#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
#include <string>

class Bankaccount
{
    private:
        std::string name;
        std::string account;
        double savings;
    public:
        Bankaccount(); // default constructor
        Bankaccount(const std::string & na, const std::string & ac, 
                    double pr);
        ~Bankaccount(); // noisy destructor
        void show();
        void add(double num);
        void reduce(double num);
};

#endif