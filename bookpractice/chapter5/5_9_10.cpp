#include <iostream>
int main()
{
    using namespace std;
    unsigned int num;
    cout << "Pleast enter a value indicating how many rows to display: ";
    cin >> num;
    for (int i = 1; i < num + 1; i ++)
    {
        for (int j = 0; j < num - i; j ++)
            cout << " . ";
        for (int k = 0; k < i; k ++)
            cout << " * ";
        cout << endl;
    }
    return 0;
}