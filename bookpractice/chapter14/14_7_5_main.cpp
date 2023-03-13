// sing the abstr_emp classes

#include <iostream>
using namespace std;

#include "14_7_5.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout << "Press a key for next phase: \n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i ++)
        tri[i]->ShowAll();
    
    return 0;
}

// 为什么没有定义赋值运算符？
// 为什么要将ShowAll()和SetAll()定义为虚的?
// 为什么要将abstr_emp定义为虚基类？
// 为什么highfink类没有数据部分？
// 为什么只需要一个operator<<()版本?
// 如果使用下面的代码替换程序的结尾部分，将会发生什么情况？
// abstr_emp tri[4] = {em, fi, hf, hf2};
// for (int i = 0; i < 4; i++)
//     tri[i].ShowAll();