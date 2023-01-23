#include <iostream>
int main()
{
    using namespace std;
    float Dsum = 100,Csum = 100;
    while (Dsum >= Csum)
    {
        Dsum += 100 * 0.10;
        Csum *= (1 + 0.05);
    }
    cout << "Daphne's investment value is: " << Dsum << endl;
    cout << "Cleo's investment value is: " << Csum << endl;
    return 0;
}