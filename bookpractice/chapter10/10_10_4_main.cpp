// using the Sales class
#include <iostream>
#include "10_10_4.h"
int main()
{
    using namespace SALES;
    double ar[2] = {233.1, 334.4};
    Sales s1 = Sales(ar, 2);
    Sales s2;
    s2.setSales();
    s1.show();
    s2.show();
    return 0;
}