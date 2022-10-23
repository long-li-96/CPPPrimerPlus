// precision problems with float
#include <iostream>
int main()
{
    using namespace std;
    float a = 2.34e+22f;
    float b = a + 1.0f;
    cout << "a = " << a << endl;
    cout << "b -a = " << b - a << endl;
    return 0;
}