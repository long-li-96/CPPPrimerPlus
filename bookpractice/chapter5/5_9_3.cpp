#include <iostream>
int main()
{
    using namespace std;
    float num,sum;
    cout << "Please enter a number" << endl;
    cin >> num;
    while (num != 0)
    {
        sum += num;
        cout << "The cumulative sum of all inputs is: " << sum << endl;
        cout << "Please enter a number again" << endl;
        cin >> num;
    }
    return 0;
}