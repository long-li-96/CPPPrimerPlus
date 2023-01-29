#include "13_11_4.h"

int main()
{
    Port p1("tesla", "top", 10);
    Port p2(p1);
    Port p3;
    p3 = p2;
    p2 += 10;
    p2 -= 5;
    cout << p2.BottleCount() << endl;
    p1.Show();
    cout << p1 << endl;
    cout << p3 << endl;

    VintagePort vp1("moutai", 100, "white wine", 1911);
    VintagePort vp2(vp1);
    VintagePort vp3;
    vp3 = vp2;
    vp2 -= 10;
    vp2.Show();
    cout << vp2.BottleCount() << endl;
    cout << vp2 << endl;
    cout << vp3 << endl;
    return 0;
}

// b
// 1、构造函数、析构函数、赋值运算符需要重新定义，无法被继承，如果派生类有new则必须重新定义
// 2、其他方法如果未改动派生类新增的私有成员，则有默认继承的基类方法
// 3、友元无法被继承

// c
// 1、友元函数不是类成员，无法virtual
// 2、赋值运算符参数不同，未virtual也会匹配到各自的方法


