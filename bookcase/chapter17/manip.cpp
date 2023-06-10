// using format manipulators
// 设置显示整数时使用的计数系统，控制符
#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter an integer: ";
    int n; 
    cin >> n;

    cout << "n n*n\n";
    cout << n << " " << n * n << " (decimal)\n";
    // set to hex mode
    cout << hex; // 十六进制
    cout << n << " ";
    cout << n * n << " (hexadecimal)\n";

    // set to octal mode
    cout << oct << n << " " << n * n << " (octal)\n"; // 八进制

    // alternative way to call a manipulator
    dec(cout); // 十进制
    cout << n << " " << n * n << " (decimal)\n";
    return 0;
}