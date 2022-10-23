#include <iostream>
#include "10_10_6.h"
int main()
{
    using namespace std;
    Move m1 = Move(1, 2);
    Move m2;
    m2.reset(2, 3);
    m2.showmove();
    Move m3 = m1.add(m2);
    m1.showmove();
    m3.showmove();
    return 0;
}