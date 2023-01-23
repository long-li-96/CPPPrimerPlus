// using the Golf class
#include <iostream>
#include "10_10_3.h"
const int num = 5;
int main()
{
    using std::cout;
    Golf golfs[num];
    int if_over = 0;
    int i = 0;
    for (i = 0; i < num; i ++) // i为数组实际元素个数
    {
        if_over = golfs[i].setgolf();
        if (!if_over) // golf对象设置失败为0
            break;
        cout << "Enter next golf player: \n";
    }
    cout << "Show all golf players' information: \n";
    for (int j = 0;j < i; j ++)
        golfs[j].showgolf();
    return 0;
}