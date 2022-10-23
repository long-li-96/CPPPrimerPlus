// some integer limits
#include <iostream>
#include <climits>
int main() // use limits.h for older systems
{
    using namespace std;
    int n_int = INT_MAX; // initialize n_int to max int value
    short n_short = SHRT_MAX; // initialize n_short to max short value
    long n_long = LONG_MAX; // initialize n_long to max long value
    long long n_llong = LLONG_MAX; // initialize n_llong to max long long value

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maxinum values: " << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Mininum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    return 0;
}