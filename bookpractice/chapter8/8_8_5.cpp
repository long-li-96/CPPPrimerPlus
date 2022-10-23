#include <iostream>
template <typename T>
T max5(T * p);
int main()
{
    using namespace std;
    int a[5] = {1,2,3,4,2};
    double b[5] = {1.1,2.1,3.1,4.1,2.1};
    cout << max5(a) << endl;
    cout << max5(b) << endl;
    return 0;
}

template <typename T>
T max5(T * p)
{
    T max = *p;
    for (int x = 0;x < 5;x++)
    {
        if (max < *(p+x))
            max = *(p+x);
    }
    return max;
}
