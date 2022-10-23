// convert light years to astronomical units
#include <iostream>
double lightyears_to_astronomicalunits(double);
int main()
{
    using namespace std;
    double lightyears,astronomicalunits;
    cout << "Enter the number of light years: ";
    cin >> lightyears;
    astronomicalunits = lightyears_to_astronomicalunits(lightyears);
    cout << lightyears << " light years " << "= " << astronomicalunits << " astronomical units.";
}
double lightyears_to_astronomicalunits(double lightyears)
{
    return 63240 * lightyears;
}