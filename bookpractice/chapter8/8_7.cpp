/*
1、哪种函数适合定义为内联函数？
只有一行代码的小型、非递归函数适合作为内联函数。

3、编写iquote()的重载版本--显示其用双引号括起的参数。编写3个版本：一个用户int参数，
一个用于double参数，另一个用于string参数。
#include <iostream>
void iquote(int n)
{
    cout << "\"" << n << "\"";
}
void iquote(double x)
{
    cout << '"' << x << '"';
}
void iquote(const char * str)
{
    cout << "\"" << str << "\"";
}

4、下面是一个结构模板：
struct box
{
    char market[40];
    float height;
    float width;
    float length;
    float volume;
};
a、编写一个函数，它将box结构的引用作为形参，并显示每个成员的值。
void show_box(const box & container)
{
    cout << "Made by " << container.market << endl;
    ...
}
b、编写一个函数，它将box结构的引用作为形参，并将volume成员设置为其他三边的乘积
void set_volume(box & crate)
{
    crate.volume = crate.height * crate.width * crate.length;
}

6、指出下面每个目标是否可以使用默认参数或函数重载完成，或者这两种方法都无法完成，
并提供合适的原型。
a、mass(density, volume)返回米的为density、体积为volume的物体的质量，而mass(densitity)
返回密度为density、体积为1.0立方米的物体的质量。这些值的类型都为double。
提供默认值：
double mass(double d, double v = 1.0);
函数重载：
double mass(double d, double v);
double mass(double d);
b、repeat(10, "I'm OK")将指定的字符串显示10次，而repeat("But you're kind of stupid")将指定的字符
串显示5次。
不能为重复的值使用默认值，因为必须从右到左提供默认值。重载：
void repeat(int times, const char * str);
void repeat(const char * str);
c、average(3,6)返回两个int参数的平均值(int类型),而average(3.0, 6.0)返回两个double值的平均值(double类型)
int average(int a, int b);
double average(double x, double y);
d、mangle("I'm glad to meet you")根据是将至赋给char变量还是char*变量，分别返回字符I和指向字符串
“I'm mad to gleet you”的指针。
不能因为两个版本的特征标将相同

7、编写返回两个参数中较大值的函数模板。
template<class T>
T max(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

8、给box结构，提供一个模板具体化，它接受两个box参数，并返回体积较大的一个。
template<> box max(box b1, box b2)
{
    return b1.volume > b2.volume ? b1 : b2;
}

9、在下述代码中，v1、v2、v3、v4和v5分别是哪种类型？
int g (int x);
...
float m = 5.5f;
float & rm = m;
decltype(m) v1 = m; // float，decltype(m)类型为m的类型float
decltype(rm) v2 = m; // float & 
decltype((m)) v3 = m; // (m)特殊处理，float &
decltype(g(100)) v4; // 与g(100)的返回值类型一致：int
decltype(2.0 * m) v5; // 2.0的类型为double,2.0f才是float，所以是double

C++11 后置返回类型
我事先不知道函数的返回类型怎么办？
template<class T1, class T2>
auto gt (T1 x, T2 y) -> decltype(x + y)
{
    ...
    return x + y;
}

优先级：非模板函数（函数重载）> 显示具体化 > 模板
模板函数：
template <typename T> void Swap(T &, T &);  // 原型没有指定类型
显示具体化：// 特征标与模板相同
template<> void Swap<job> (job & , job &); // 原型使用指定类型
or
template<> void Swap(job &, job &);
模板的显示实例化：
Swap<double>(x, y); // 直接函数调用
or
template void Swap<double> (double & , double &); // 先声明原型，脱裤子放屁，只是可以提前检查，提高编译速度
double a;
double b;
Swap(a, b); // 函数调用

模板的隐式实例化：
int r;
int t;
Swap(r, t);

*/