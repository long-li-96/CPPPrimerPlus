// Enter the number of seconds as an integer, and display the time in days, hours, minutes, and seconds
#include <iostream>
const int second_per_minute = 60, minute_per_hour = 60, hour_per_day = 24;

int main()
{
    using namespace std;
    long time_by_seconds;
    int left_time,days,hours,minutes,seconds;
    cout << "Enter the number of seconds: ";
    cin >> time_by_seconds;
    days = time_by_seconds / (second_per_minute * minute_per_hour * hour_per_day);
    left_time = time_by_seconds % (second_per_minute * minute_per_hour * hour_per_day);
    hours = left_time / (second_per_minute * minute_per_hour);
    left_time = left_time % (second_per_minute * minute_per_hour);
    minutes = left_time / second_per_minute;
    seconds = left_time % second_per_minute;
    cout << time_by_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
    return 0;
}