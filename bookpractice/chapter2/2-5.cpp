// convert celsius to fahrenheit
#include <iostream>
double Celsius_to_Fahrenheit(double);
int main()
{
    using namespace std;
    double Celsiusvalue,Fahrenheitvalue;
    cout << "Please enter a Celsius value: ";
    cin >> Celsiusvalue;
    Fahrenheitvalue = Celsius_to_Fahrenheit(Celsiusvalue);
    cout << Celsiusvalue << " degrees Celsuis is " << Fahrenheitvalue << " degrees Fahrenheit.";
}
double Celsius_to_Fahrenheit(double cvalue)
{
    double fvalue;
    fvalue = 1.8 * cvalue + 32.0;
    return fvalue;
}
