// using the conditional operator
#include <iostream>
int main()
{
    using namespace std;
    int a,b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a>b? a: b;
    cout << " is " << c << endl;
    return 0;
}