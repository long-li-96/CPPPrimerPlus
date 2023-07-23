// callable types and templates
#include "somedefs.h"
#include <iostream>

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main()
{
    using std::cout;
    using std::endl;

    double y = 1.21;
    cout << "Function pointer dub: \n";
    cout << " " << use_f(y, dub) << endl; // 参数为double、函数指针(函数名就是函数指针)
    cout << "Function pointer square:\n";
    cout << " " << use_f(y, square) << endl;// 参数为double、函数指针(函数名就是函数指针),与第一次实例化相同,第一个
    cout << "Function object Fp:\n";
    cout << " " << use_f(y, Fp(5.0)) << endl; // 第二个
    cout << "Function object Fq:\n";
    cout << " " << use_f(y, Fq(5.0)) << endl; // 第三个
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, [] (double u) {return u*u;}) << endl; // 第四个
    cout << "Lambda expression 2: \n";
    cout << " " << use_f(y, [](double u) {return u+u/2.0;}) << endl; // 第五个

    return 0;
}
// 实际为相同参数的模板调用被实例化了多次
