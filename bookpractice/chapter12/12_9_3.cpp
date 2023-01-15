#include "12_9_3.h"

Stock::Stock()
{
    company = new char[8];
    std::strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    int len = std::strlen(co);
    company = new char[len+1];
    std::strcpy(company, co);
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

Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negetive. "
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
        cout << "Number of shares sold can't be nagetive. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
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

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else 
        return * this;
}

ostream & operator<<(ostream & os, const Stock & s)
{
    using std::ios_base;

    // set format to #.###
    ios_base::fmtflags orig = 
        os.setf(ios_base::fixed, ios_base::floatfield); // 设置浮点数输出
    std::streamsize prec = os.precision(3); // 设置精度
    os << "Company: " << s.company << " Shares: " << s.shares << '\n';
    os << " Share_Price: $" << s.share_val;

    os.precision(2);
    os << " Total Worth: $" << s.total_val << '\n';

    // restore original format
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    
    return os;
}