// sing the abstr_emp classes

#include <iostream>
using namespace std;

#include "14_7_5.h"

int main(void)
{
    // employee em("Trip", "Harris", "Thumper");
    // cout << em << endl;
    // em.ShowAll();
    // manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    // cout << ma << endl;
    // ma.ShowAll();

    // fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    // cout << fi << endl;
    // fi.ShowAll();
    // highfink hf(ma, "Curly Kew"); // recruitment?
    // hf.ShowAll();
    // cout << "Press a key for next phase: \n";
    // // cin.get();
    // highfink hf2;
    // hf2.SetAll();

    // cout << "Using an abstr_emp * pointer:\n";
    // abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    // for (int i = 0; i < 4; i ++)
    //     tri[i]->ShowAll();

    abstr_emp * tri[4];
    for (int i = 0; i < 4; i ++)
    {
        switch (i)
        {
        case 0:
            tri[i] = new employee;
            tri[i]->SetAll();
            tri[i]->ShowAll();
            cout << & (tri[i]) << endl;
            break;
        case 1:
            tri[i] = new manager;
            tri[i]->SetAll();
            tri[i]->ShowAll();
            cout << & (tri[i]) << endl;
            break;
        case 2:
            tri[i] = new fink;
            tri[i]->SetAll();
            tri[i]->ShowAll();
            cout << & (tri[i]) << endl;
            break;
        case 3:
            tri[i] = new highfink;
            tri[i]->SetAll();
            tri[i]->ShowAll();
            cout << & (tri[i]) << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}

// 为什么没有定义赋值运算符？
// 因为没有动态分配内存，所以可以用编译器默认提供的赋值运算符

// 为什么要将ShowAll()和SetAll()定义为虚的?
// 派生类可以继承接口，对接口定义实现自己的定制

// 为什么要将abstr_emp定义为虚基类？
// 公有MI防止派生类有多个继承过来的abstr_emp

// 为什么highfink类没有数据部分？
// highfink继承了fink、manager的数据部分

// 为什么只需要一个operator<<()版本?
// 这个友元方法也被派生类继承

// 如果使用下面的代码替换程序的结尾部分，将会发生什么情况？
// abstr_emp tri[4] = {em, fi, hf, hf2};
// for (int i = 0; i < 4; i++)
//     tri[i].ShowAll();
// 不用指针无法实现类的多态，tri数组内元素实际上都是abstr_emp对象，不用指针就限定了元素的数据类型