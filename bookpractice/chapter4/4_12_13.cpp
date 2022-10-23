#include <iostream>
#include <vector>
int main()
{
    using namespace std;
    unsigned int n;
    cout << "Please enter a number greater than 0: ";
    cin >> n;
    int * ps = new int [n];
    vector<int> pa(n);
    delete [] ps;
    return 0;
}