// variable with internal and external linkage
#include <iostream>
extern int tom; // tom defined elsewhere
static int dick = 10; // overrides external dick
int harry = 20; // external variable definition
                // no conflict with twofile harry

void remote_access()
{
    using namespace std;
    cout << "romote_access() reports the following address:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}