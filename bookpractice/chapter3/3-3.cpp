// Enter a latitude in degrees, minutes, seconds, and display the latitude in degrees
#include <iostream>
const int second_per_minute = 60;
const int minute_per_degree = 60;
int main()
{
    using namespace std;
    int degrees,minutes,seconds;
    double latitude;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter eht degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;
    latitude = degrees + double (minutes) / minute_per_degree + double (seconds) / (second_per_minute * minute_per_degree);
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << latitude << " degrees";
    return 0;
}