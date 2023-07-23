// using recursion to unpack a parameter pack
// 使用递归展开参数包

#include <iostream>
#include <string>

// definition for 0 parameters -- terminating call
void show_list3() {}

// definition for 1 or more parameters
template <typename T, typename... Args> // Args是一个模板类型列表
void show_list3(T value, Args... args) // args是一个函数参数列表 ...放函数参数包名的右边表示将参数包展开
{
    std::cout << value << ", ";
    show_list3(args...); // args...的第一个参数又被赋给value，其他剩余的又赋给args,每次调用减少一项，直到匹配show_list3(void)结束递归
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list3(n, x);
    show_list3(x * x, '!', 7, mr);
    return 0;
}