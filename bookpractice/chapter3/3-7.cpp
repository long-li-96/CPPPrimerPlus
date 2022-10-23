// Conversion between diffent fuel consumption
#include <iostream>
const double mile_per_100km = 62.14, litre_per_gallon = 3.785;
double mpg_to_lpk(double);
double lpk_to_mpg(double);

int main()
{
    using namespace std;
    cout << "Please choose a conversion between the two consumption: " << endl;
    cout << "1. Convert litre per 100km into miles per gallon" << endl;
    cout << "2. Convert miles per gallon into litre per 100KM" << endl;
    int option;
    double mpg,lpk;
    cin >> option;
    loop: if (option == 1)
          {
              cout << "enter the fuel consumption: ";
              cin >> lpk;
              mpg = lpk_to_mpg(lpk);
              cout << lpk << " litre per 100KM" << " = " << mpg << " miles per gallon";
          }
          else
          {
              if (option == 2)
              {
                  cout << "enter the fuel consumption: ";
                  cin >> mpg;
                  lpk = mpg_to_lpk(mpg);
                  cout << mpg << " miles per gallon" << " = " << lpk << "litre per 100KM";
              }
              else
              {
                  cout << "Invalid number in input, please enter again" << endl;
                  cin >> option;
                  goto loop;
              }
          }
    return 0;
}

double lpk_to_mpg(double lpk)
{
    double mpg;
    mpg = (litre_per_gallon * mile_per_100km) / lpk;
    return mpg;
}

double mpg_to_lpk(double mpg)
{
    double lpk;
    lpk = (mile_per_100km * litre_per_gallon) / mpg;
    return lpk;
}