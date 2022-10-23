// Calculate the fuel consumption of a car
#include <iostream>
int main()
{
    using namespace std;
    double mpg,litre_per_100km;
    cout << "Which fuel consumption do you want to work out: " << endl;
    cout << "1. miles per gallon" << endl << "2. litre_per_100km" << endl;
    int option;
    cin >> option;
    loop: if (option == 1)
        {
            double mileage, gallon;
            cout << "Please enter mileage of your car: ";
            cin >> mileage;
            cout << "fuel consumption by gallon: ";
            cin >> gallon;
            mpg = mileage / gallon;
            cout << "The fuel consumption of your car is: " << mpg << " mpg";
        }
        else 
        {
            if (option == 2)
            {
                double litre, kilometers;
                cout << "Please enter kilometer mileage of your car: ";
                cin >> kilometers;
                cout << "fuel consumption by litre: ";
                cin >> litre;
                litre_per_100km = litre / (kilometers / 100);
                cout << "The fuel consumption of your car is " << litre_per_100km << " l/100km";
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