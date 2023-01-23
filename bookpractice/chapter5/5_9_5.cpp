#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string month[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int sales_volume[12],sum=0;
    for (int i = 0; i < 12; i ++)
    {
        cout << "Please enter sales volume of " << month[i] << ": ";
        cin >> sales_volume[i];
        sum += sales_volume[i];
    }
    cout << "The sales volume of this year is: " << sum;
    return 0;
}