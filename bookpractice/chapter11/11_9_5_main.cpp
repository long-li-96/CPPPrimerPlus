#include "11_9_5.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    using namespace std;
    srand(time(0)); // seed random-number generator
    Stonewt s1;
    Stonewt s2(1);
    cout << -s2 << s2 + s1 << s2 - s1 << 2 * s2 << s2 * 2;
    return 0;
}