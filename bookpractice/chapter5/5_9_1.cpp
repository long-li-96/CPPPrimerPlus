#include <iostream>
int main()
{
    using namespace std;
    int k, f, sum = 0;
    cout << "Please enter two different integer(the first number is less than the second number): ";
    cin >> k;
    cin >> f;
    for (int i = k; i <= f; i++)
        sum += i;
    cout << k << "-" << f << " aggregate is " << sum;
    return 0;
}