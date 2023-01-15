// stock
#ifndef STOCK_H_
#define STOCK_H_
#include <iostream>
#include <cstring>

using std::ostream;
class Stock
{
    private:
        char * company;
        int shares;
        double share_val;
        double total_val;
        static const int CINLIM = 80;
        void set_tot()
        {
            total_val = shares * share_val;
        }
    
    public:
        Stock();
        Stock(const char * str, long n = 0, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        const Stock & topval(const Stock & s) const;
        // overloaded operator friends
        friend ostream & operator<<(ostream & os, const Stock & s);
};

#endif