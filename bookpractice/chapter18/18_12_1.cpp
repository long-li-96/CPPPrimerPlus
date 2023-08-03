/*
给以下程序提供average_list()，让该程序变得完整。它应该是一个模板函数，其中的类型
参数指定了用作函数参数的initializer_list模板的类型及函数的返回类型。
*/
#include <iostream>
/*
在C++中，函数或者类方法可以返回引用，但是你需要确保引用的对象在函数返回后仍然存在。通常，这意味着你不能返回指向局部变量的引用，因为局部变量在函数返回后就会被销毁。
然而，如果你返回的是类的成员变量的引用，或者是传入的参数的引用，那么这通常是安全的，因为这些对象在函数返回后仍然存在。
*/
template <typename T>
T average_list(std::initializer_list<T> Tlist) // initializer_list 不定长常量列表，用于列表初始化
{
    T total = 0;
    for (auto p = Tlist.begin(); p != Tlist.end(); p++) // Tlist.begin() 是指向Tlist第一个元素的迭代器，类型是const T *
        total += *p;
    // 使用for_each()也可实现
    // std::for_each(Tlist.begin(), Tlist.end(), [&total](T t){total += t;});
    return total / Tlist.size(); 
}

int main() 
{
    using namespace std;
    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0}); // 模板隐式实例化：编译器自动根据传进去的实参类型，推断模板参数
    cout << q << endl;
    // list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl; // 模板隐式实例化
    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33}); // 模板显式实例化
    cout << ad << endl;
    return 0;
}