// initialize a pointer
#include <iostream>
int main()
{
    using namespace std;
    int higgens = 5;
    int* pt = &higgens; // 初始化指针值为变量higgens的地址
    cout << "Value of higgens = " << higgens
         << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
         << "; Value of pt = " << pt << endl;
    return 0;
}