#include "9_6_4.h"
using namespace SALES;
int main()
{
    Sales s1,s2;
    double ar[2] = {426.3,580.66};
    setSales(s1,ar,2);
    setSales(s2);
    std::cout << "s1: " << std::endl;
    showSales(s1);
    std::cout << "s2: " << std::endl;
    showSales(s2);
    return 0;
}