/*
编写一个有关计算的函数：
calculate(double,double,double(*ptr_f)(double,double))
函数参数为两个double的数以及一个指向函数的指针
calculate()类型是double,返回被指向函数的计算结果
如：
double add(double x,double y)
{
    return x+y;
}
double q = calculate(2.0,5.0,add);
*/
#include <iostream>
#include <string>
using namespace std;
double calculate(double a,double b,double(*ptr_f)(double,double))
{
    return (*ptr_f)(a,b);
}

double add(double a,double b)
{
    return a+b;
}

double sub(double a,double b)
{
    return a-b;
}

double times(double a,double b)
{
    return a*b;
}

int main()
{
    double a,b;
    double (*ptr_f[3])(double,double) = {add,sub,times}; // 函数指针数组
    string s[3] = {"add","sub","times"};
    cout << "输入非数字退出" << endl;
    while (cin>>a>>b)
    {
        for (int i = 0;i<3;i++)
        {
            cout << s[i] << ":" << a;
            if (s[i] == "add")
                cout << "+";
            else if (s[i] == "sub")
                cout << "-";
            else 
                cout << "*";
            cout << b << "=" << calculate(a,b,ptr_f[i]) << endl;
        }
    }
    return 0;
}