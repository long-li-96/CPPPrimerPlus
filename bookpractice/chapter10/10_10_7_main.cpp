#include <iostream>
#include "10_10_7.h"
int main()
{
    using namespace std;
    Plorg pl1 = Plorg("test", 1);
    Plorg pl2;
    pl1.show();
    pl1.resetCI(100);
    pl1.show();
    pl2.show();
    return 0;
}