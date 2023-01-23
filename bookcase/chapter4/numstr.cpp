// following number input with line input
#include <iostream>
int main()
{
    using namespace std;
    cout << "What year was your houst built?\n";
    int year;
    cin >> year;
    cin.get(); // 捕获换行,防止影响下次输入
    cout << "What is its street address?\n";
    char address[80];
    //cin >> address;
    cin.getline(address,80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}
// cin根据换行符判读字符串是否结束，不包括数字