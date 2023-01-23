// regular and reference arguments
#include <iostream>
double cube(double a);
double refcube(double &ra);
int main()
{
    using namespace std;
    double x = 3.0;
    
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a) // 重新生成一个对象返回，不改变传进来的参数数据
{
    a *= a*a;
    return a;
}

double refcube(double &ra) // 使用引用对传进来的参数数据更改
{
    ra *= ra * ra;
    return ra;
}