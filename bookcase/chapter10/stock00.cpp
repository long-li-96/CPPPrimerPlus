// implementing the Stock class /使Stock 类生效
// version 00
#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co; // 调用string类的赋值操作符方法
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else 
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative."
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
        using std::cout;
        if (num < 0)
        {
            cout << "Number of shares sold can't be nagative."
                 << "Transaction is aborted.\n";
        }
        else if (num > shares)
        {
            cout << "You can't sell moren than you have!"
                 << "Transaction is aborted.\n";
        }
        else 
        {
            shares -= num;
            share_val = price;
            set_tot();
        }
}

void Stock::update(double price)
{
        share_val = price;
        set_tot();
}

void Stock::show()
{
//         std::cout << "Company: " << company
//                   << " Shares: " << shares << '\n'
//                   << " Share Price: $" << share_val
//                   << " Total Worth: $" << total_val << '\n';

    using std::cout;
    using std::ios_base;

    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company 
         << " Shares: " << shares << '\n';
    cout << " SHARES Price: $" << share_val;

    // set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}
