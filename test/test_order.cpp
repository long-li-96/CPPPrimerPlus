#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int a[] = {1,2,3,4,5};
    int i = 3;
    cout << a[i] << endl;
    a[i++] = 10;
    cout << i << endl;
    for (int j = 0; j < 5; j ++)
        cout << a[j];
    cout << endl;
    cout << a[i] << endl;
    int b = a[--i];
    cout << b << endl;
    return 0;
}