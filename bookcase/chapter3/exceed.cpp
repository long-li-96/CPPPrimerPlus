// exceeding some integer limits
#include <iostream>
#define ZERO 0 // makes ZERO symbol for 0 value
#include <climits> //define INT_MAX as largest int value
int main()
{
    using namespace std;
    short sam = SHRT_MAX; // initialize a variable to max short value
    unsigned short sue = sam; // okay if variable sam already defined

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl
         << "And $1 to each account." << endl << "Now ";
    sam += 1;
    sue += 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl;
    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";
    sam -= 1;
    sue -= 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    return 0;
}
