#include <iostream>
using namespace std;
long long factorial(int n);
int main()
{
    int N = 0;
    cout << "Please enter the number of factorial required('q' to quit): ";
    while (cin >> N && N >= 0)
    {
        cout << N << " of factorial is: " << factorial(N) << endl;
        cout << "Please enter the number of factorial required('q' to quit): ";
    }
    return 0;
}
long long factorial(int n)
{

    if (n == 0)
        return 1;
    else if (n < 3)
        return n;
    else
        return n * factorial(n-1);
}
// 递归求斐波那契数列