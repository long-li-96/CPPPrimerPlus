// choosing a template
#include <iostream>

// 泛型，定义一个泛型模板来代替函数定义的类型
template <class T> // or template <typename T>
T lesser(T a, T b) // #1 T表示 int、double、long等类型
{
    return a < b ? a:b;
}

int lesser(int a,int b) // #2
{
    a = a<0 ? -a:a;
    b = b<0 ? -b:b;
    return a<b ? a:b;
}

int main()
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m,n) << endl; // use #2
    cout << lesser(x,y) << endl; // use #1 with double
    cout << lesser<>(m,n) << endl; // use #1 with int <>告诉编译器使用模板，编译器发现参数为int，则使用int代替T
    // 实例化函数
    cout << lesser<int>(x,y) << endl; // use #1 with int 使用int代替T显式实例化函数
    return 0;
}