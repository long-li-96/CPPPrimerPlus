// 添加一个处理一项的模板，行为与通用模板稍有不同
// 在可变参数模板中，指定展开模式pattern const T & 
#include <iostream>
#include <string>

// definition for 0 parameters
void show_list() {}

// definition for 1 parameters
template<typename T>
void show_list(const T & value)
{
    std::cout << value << '\n';
}

// definition for 2 or more parameters
template< typename T, typename... Args>
void show_list(const T & value, const Args & ... args)
{
    std::cout << value << ", ";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String object!";
    show_list(n, x);
    show_list(x * x, '!', 7 , mr);
    return 0;
}
