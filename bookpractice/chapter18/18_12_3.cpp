/*
编写并测试可变参数模板函数sum_vlue(), 它接受任意长度的参数列表(其中包含数值，但可以是任何类型)，
并以long double的方式返回这些数值的和。
*/

#include <iostream>

long double sum_value() {long double sumvalue = 0.0; return sumvalue;};
template<typename T>
long double sum_value(const T & value)
{
    return sum_value() + (long double) (value); 
}
template<typename T, typename... Args>
long double sum_value(const T & value, const Args & ... args)
{
    // return sum_value(value) + sum_value(args...); // 这会导致只有一个参数的时候无限递归
    return (long double) (value) + sum_value(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    // std::string mr = "Mr. String object!";
    std::cout << sum_value(n) << '\n';
    std::cout << sum_value(n, x) << '\n';
    std::cout << sum_value(x * x, x/n, 7 , 10.0, '!') << '\n';
    return 0;
}
