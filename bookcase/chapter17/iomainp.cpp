// using manipulators from immanip(简化设置格式值)
// some systems require explicitly linking the math library
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;
    // use new standard manipulators
    cout << fixed << right; // 使用fixed控制符，导致显示末尾的0

    // use iomanip manipulators
    cout << setw(6) << "N" << setw(14) << "squre root" // setw()控制符用来设置字段款的
         << setw(15) << "fourth root\n";

    double root;
    for (int n = 10; n <=100; n+=10)
    {
        root = sqrt(double (n));
        cout << setw(6) << setfill('.') << n << setfill(' ') // setfill()控制符设置填充字符
             << setw(12) << setprecision(3) << root // setprecision()控制符用来设置精度
             << setw(14) << setprecision(4) << sqrt(root)
             << endl;
    }
    return 0;
}