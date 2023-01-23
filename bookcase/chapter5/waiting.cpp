// using clock() in a time-delay loop
#include <iostream>
#include <ctime> //describes clock() function, clock_t type
int main()
{
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay =secs * CLOCKS_PER_SEC;   // convert to clock ticks CLOCKS_PER_SEC每秒的时钟单元
    cout << "starting\a\n";
    clock_t start = clock(); // clock_t 时钟单元的类
    while (clock() - start < delay) // wait until time elapses
        ; // note the semicolon
    cout << "done \a\n";
    return 0;
}