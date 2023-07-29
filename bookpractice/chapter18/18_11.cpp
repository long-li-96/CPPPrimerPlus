/*
1、使用用大括号括起的初始化列表语法重写下述代码。重写后的代码不应使用数组ar：
class Z200
{
    private:
        int j;
        char ch;
        double z;
    public:
        Z200(int jv, char chv, zv) : j(jv), ch(chv), z(zv) {}
    ...
};
double x = 8.8;
std::string s = "What a bracing effect!";
int k(99);
Z200 zip(200,'z',0.675);
std::vector<int> ai(5);
int ar[5] = {3, 9, 4, 7, 1};
for (auto pt = ai.begin(), int i = 0; pt != ai.end(); ++pt ++i)
    *pt = ai[i];

class Z200
{
    private:
        int j;
        char ch;
        double z;
    public:
        Z200(int jv, char chv, zv) : j(jv), ch(chv), z(zv) {}
    ...
}
double x{8.8}; // or = {8.8}
std::string s{"What a bracing effect!"};
int k{99};
Z200 zip{200, 'Z', 0.67};
std::vector<int> ai {3, 9, 4, 7, 1};
*/ 

/*
2、在下述简短的程序中，哪些函数调用不对？为什么？对于合法的函数调用，指出其引用参数指向的是什么。
#include <iostream>
using namespace std;
double u(double x) {return 2.0 * x; }
void r1(const double &rx) {cout << rx << endl;}
void r2(double &rx) {cout << rx << endl;}
void r3(double && rx) {cout << rx << endl;}
int main()
{
    double w = 10.0;
    r1(w); // rx 指向w
    r1(w+1); // rx指向一个临时变量，这个变量被初始化为w+1
    r1(up(w)); // 合法，rx指向一个临时变量，这个变量为初始化为up(w)的返回值
    // 一般而言，将左值传递给const左值引用参数时，参数将被初始化为左值。将右值传递给函数时，const左值
    // 引用参数将指向右值的临时拷贝。
    r2(w); // rx指向w
    r2(w+1); // 非法，w+1是一个右值
    r2(up(w)); // 非法,up(w)返回的是一个右值
    r3(w); // 非法，因为右值引用参数不能指向左值
    r3(w+1); // rx指向表达式w+1的临时拷贝
    r3(up(w)); // rx指向up(w)的临时返回值
}
*/

/*
3、a. 下述简短的程序显示什么？为什么？
#include <iostream>
using namespace std;
double up(double x) {return 2.0 * x; }
void r1(const double &rx) {cout << "const double & rx\n";}
void r1(double & rx) {cout << "double & rx\n";}
int main()
{
    double w = 10.0;
    r1(w);
    r1(w+1);
    r1(up(w));
    return 0;
}
double & rx
const double & rx
const double & rx
非const左值引用与左值实参w匹配，右值实参，const左值引用可指向它们的拷贝

b
#include <iostream>
using namespace std;
double up(double x) {return 2.0 * x;}
void r1(double & rx) {cout << "double & rx\n";}
void r1(double && rx) {cout << "double && rx\n";}
int main()
{
    double w = 10.0;
    r1(w);
    r1(w+1);
    r1(up(w));
    return 0;
}
double & rx
doubel && rx
double && rx
左值引用与左值实参w匹配，而右值引用与两个右值实参匹配

c
#include <iostream>
using namespace std;
double up(double x) {return 2.0 * x;}
void r1(const double & rx) {cout << "const double & rx\n";}
void r1(double && rx) {cout << "double && rx\n";}
int main()
{
    double w = 10.0;
    r1(w);
    r1(w+1);
    r1(up(w));
    return 0;
}
double & rx
double && rx
double && rx
const左值引用与左值实参w匹配，而右值引用与两个右值实参匹配

总之，非const左值形参与左值实参匹配，非const右值形参与右值实参匹配；const左值形参可与左值或右值形参匹配，
但编译器优先选择前两种模式（如果可供选择的话）
*/

/*
4、哪些成员函数是特殊的成员函数？它们特殊的原因是什么？
它们是默认构造函数、复制构造函数、移动构造函数、析构函数、复制赋值运算符和移动赋值运算符。因为编译器将根据
情况自动提供它们的默认版本。
*/

/*
5、假设Fizzle类只有如下所示的数据成员：
class Fizzle
{
    private:
        double bubbles(4000);
    ...
};
为什么不适合给这个类定义移动构造函数？要让这个类适合定义移动构造函数，应如何修改存储4000个double值的方式？
在转让数据所有权（而不是复制数据）可行时，可使用移动构造函数，但对于标准数组，没有转让其所有权的机制。如果
Fizzle使用指针和动态内存分配，则可将数据的地址赋给新指针，以转让其所有权。

class Fizzle
{
    private:
        int n;
        double * bubbles;
    public:
        Fizzle(int k, double d): n(k) {
            bubbles = new double[n];
            for (int i = 0; i < n; i ++)
                *(bubbles+i) = d;
        }

        Fizzle(Fizzle && f) : n(f.n)
        {
            bubbles = f.bubbles;
            f.bubbles = nullptr;
        }
};
*/

/*
6、修改下述简短的程序，使其使用lambda表达式而不是f1()。请不要修改show2()。
#include <iostream>
template<typename T>
void show2(double x, T & fp) {std::cout << x << " -> " << fp(x) << '\n';}
double f1(double x) {return 1.8 * x + 32;}
int main()
{
    show2(18.0, f1);
    return 0;
}

#include <iostream>
template<typename T>
void show2(double x, T & fp) {std::cout << x << " -> " << fp(x) << '\n';}
auto f = [] (double x) {return 1.8 * x + 32;}
int main()
{
    show2(18.0, f);
    return 0;
}
*/

/*
7、修改下面的程序，使其使用lambda表达式而不是函数符Adder。不要修改sum().
#include <iostream>
#include <array>
const int Size = 5;
template <typename T>
void sum(std::array<double, Size> a, T& fp);
class Adder
{
    double tot;
public:
    Adder(double q = 0) : tot(q) {}
    void operator() (double w) {tot += w;}
    double tot_v () const {return tot;};
};
int main()
{
    double total = 0.0;
    Adder ad(total);
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c, ad);
    total = ad.tot_v();
    std::cout << "total: " << ad.tot_v() << '\n';
    return 0;
}
template <typename T>
void sum(std::array<double,Size> a, T & fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(* pt);
    }
}

#include <iostream>
#include <array>
const int Size = 5;
template <typename T>
void sum(std::array<double,Size> a, T & fp);
int main()
{
    double total = 0.0;
    auto ad = [&total] (double & w) {total += w;};
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c, ad);
    std::cout << "total: " << total << '\n';
    return 0;
}
template <typename T>
void sum(std::array<double, Size> a, T & fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
        fp(* pt);
}
*/
