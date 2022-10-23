//display digital time
#include <iostream>
using namespace std;
void displaydigitaltime(int,int);
int main()
{
    int hours,minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    displaydigitaltime(hours,minutes);
    return 0;
}
void displaydigitaltime(int hours,int minutes)
{
    cout << "Time: " << hours << ":" << minutes;
}