// simple uses of rvalue references
// 右值引用，引用绑定右值，可通过&取这个右值的地址
// 这个右值可以是一个常量、表达式、函数
#include <iostream>

inline double f(double tf) { return 5.0 * (tf - 32.0) / 9.0;}

int main()
{
    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07; // 定义rd1为7.07的右值引用
    double && rd2 = 1.8 * tc + 32.0;
    double && rd3 = f(rd2); // 转化为float?
    cout << "tc value and address: " << tc << ", " << &tc << endl;
    cout << "rd1 value and address: " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 value and address: " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 value and address: " << rd3 << ", " << &rd3 << endl;
    cin.get();
    return 0;
}