// use a block statement
#include <iostream>
int main()
{
    using namespace std;
    cout << "The Amazing Accouto will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Please enter five values: \n";
    double number, sum = 0.0;
    for (int i = 1;i <= 5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }
    cout << "Five exquistite choice indeed! ";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << ".\n";
    cout << "The Amazing Accouto bids you adieu!\n";
    return 0;
}