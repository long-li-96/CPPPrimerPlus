// using recursion
#include <iostream>
void countdown(int n);

int main()
{
    countdown(4); // call the recursive function
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ... " << n << "(n at " << &n << ")" << endl;
    if (n > 0)
        countdown(n-1); // function call ifself
    cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}