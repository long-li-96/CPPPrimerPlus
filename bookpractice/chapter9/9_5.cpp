/*
1、对于下面的情况，应使用哪种存储方案？
a. homer是函数的形参
将自动成为自动变量
b. secret变量由两个文件共享。
应该在一个文件中将secret定义为外部变量，并在第二个文件中使用extern来声明它。
在主函数外面定义的变量即为外部变量（不在任意函数内）
c. topsecret变量由一个文件中的所有函数共享，但对于其他文件来说是隐藏的。
（1）在外部定义前加上static
（2）在一个未命名的名称空间中进行定义
d. beencalled记录包含它的函数被调用的次数。
在函数中的声明前加上static

2、using声明和using编译指令之间有何区别？
using声明是的名称空间中的单个名称可用，其作用域与using所在的声明区域相同。using编译
指令使名称空间中的所有名称可用。

5、在一个文件中调用average(3, 6)函数时，它返回两个int参数的int平均值，在同一个程序的另一个文件中调用
时，它返回两个int参数的double平均值。
在每个文件中包含单独的静态函数定义。或者每个文件都在未命名的名称空间中定义一个合适的average()函数。

6、下面的程序由两个文件组成，该程序显示什么内容？
// file1.cpp
#include <iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;
int main()
{
    cout << x << endl;
    {
        int x = 4;
        cout << x << endl;
        cout << y << endl;
    }
    other();
    another();
    return 0;
}
void other()
{
    int y =1;
    cout << "Other: " << x < ", " << y << endl;
}
// file2.cpp
#include <iostream>
using namespace std;
extern int x;
namespace // 没有命名的名称空间，只在当前文件生效
{
    int y = -4;
}
void another()
{
    cout << "another(): " << x << ", " << y << endl;
}
10
4
0 // y随机，因为没有初始值
Other: 10, 1
another(): 10, -4

7、下面的代码将显示什么内容？
#include <iostream>
using namespace std;
void other();
namespace n1
{
    int x = 1;
}
namespace n2
{
    int x = 2;
}
int main()
{
    using namespace n1;
    cout << x << endl;
    {
        int x = 4;
        cout << x < ", " << n1::x << ", " << n2::x << endl;
    }
    using n2::x;
    cout << x << endl;
    other();
    return 0;
}
void other()
{
    using namespace n2;
    cout << x << endl;
    {
        int x = 4;
        cout << x << ", " << n1::x << ", " << n2::x << endl;
    }
    using n2::x;
    cout << x << endl;
}
1
4,1,2
2
4,1,2
2

自动变量：代码块中
存储在寄存器中：在代码块中使用register
静态变量无链接性：代码块中使用static
静态外部变量：不在任何函数内，其他文件要用就需要使用extern
静态内部变量：不在任何函数内，使用static

静态函数：在函数返回类型前加static，不能在其他文件使用
静态成员函数：在声明前加了static，被所有同类对象共享，没有this指针，无法访问对象的成员，可以通过类直接调用
            或者对象名.函数名

*/