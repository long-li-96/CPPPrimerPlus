/*
1、iostream文件在c++I/中扮演何种角色？
iostream文件定义了用户管理输入和输出的类、常量和操纵符，这些对象管理用于处理I/O的流和缓冲区。该文件还创建
了一些标准对象（cin、cout、cerr和clog以及对应的宽字符对象），用于处理与每个程序相连的标准输入和输出流

2、为什么键入数字（121）作为输入要求程序进行转换？
键盘输入生成一系列字符。输入121将生成3个字符，每个字符都由一个1字节的二进制码表示。要将这个值存储为int类型，
则必须将这3个字符转换为121值的二进制表示

3、标准输出与标准错误之间有什么区别？
在默认情况下，标准输出和标准错误都将输出发送给标准输出设备（通常为显示器）。然而，如果要求操作系统将输出重定
向到文件，则标准输出将与文件（而不是显示器）相连，但标准错误仍与显示器相连

4、为什么在不为每个类型提供明确指示的情况下，cout仍能够现实不同的c++类型？
ostream类为每种c++基本类型定义了一个operator<<()函数的版本。编辑器将下面的表达式：
cout << spot
解释为：
cout.operator<<(spot)
这样，它便能够将该方法调用与具有相同参数类型的函数原型匹配。

5、输出方法的定义的哪一特征让您能够拼接输出？
可以将返回ostream&类型的输出方法拼接。这样，通过一个对象调用方法时，将返回该对象。然后，返回对象将可以调用序列
中的下一个方法。

6、// 编写一个程序，要求用户输入一个整数，然后以十进制、八进制和十六进制显示该整数，在宽度为15个字符的字段中
显示每种形式，并将它们显示在同一行上，同时使用c++数基前缀。
#include <iostream>
#include <iomanip>
int main()
{
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;
    // std::cout.width(15); // 使用ostream的width方法设置字段宽度为15字符，只生效一次
    // std::cout << std::setw(15); // 
    std::cout.setf(std::ios_base::showbase); // 使用c++基数前缀
    std::cout << std::dec << std::setw(15) << n << " ";
    std::cout << std::oct << std::setw(15) << n << " ";
    std::cout << std::hex << std::setw(15) << n << " ";
    return 0;
}

7、编写一个程序，请求用户输入下面的信息，并按下面的格式显示它们：
Enter your name: Billy Gruff
Enter your hourity wages: 12
Enter number of hours worked: 7.5
First format:
                    Billy Gruff: $      12.00:      7.5
Second format::
Billy Gruff                    : $12.00      :7.5
#include <iostream>
#include <iomanip>
#include <string>

struct Worker
{
    std::string name;
    float wages;
    float work_hours;
};

int main()
{
    Worker worker1;
    using namespace std;
    cout << "Enter your name: ";
    getline(cin,worker1.name);
    // cin.get();
    cout << "Enter your hourily wages: ";
    cin >> worker1.wages;
    cout << "Enter number of hours worked: ";
    cin >> worker1.work_hours;
    cout.setf(ios_base::right, ios_base::adjustfield); // 右对齐
    cout.setf(ios_base::fixed, ios_base::floatfield); // 浮点数定点显示
    cout << "First format: \n" << setw(30) << worker1.name 
         << ": $" << setw(10) << setprecision(2) << worker1.wages
         << ":" 
         << setprecision(1) << setw(5) << worker1.work_hours << endl;
    cout.setf(ios_base::left, ios_base::adjustfield); // 左对齐
    cout << "Second format: \n" << setw(30) << worker1.name << ": $"
         << setw(10) << setprecision(2) << worker1.wages 
         << ":"
         << setw(5) << setprecision(1) << worker1.work_hours << endl;
    return 0;
}

8、对于下面的程序：
// rq17-8.cpp
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int ct1 = 0;

    cin >> ch;
    while (ch != 'q')
    {
        ct1 ++;
        cin >> ch; // 不会读取空格，所以是4
    }

    int ct2 = 0;
    cin.get(ch); // 读取到了上个q之后的换行符，再加上输入的字符包括空格，共9个
    while (ch != 'q')
    {
        ct2++;
        cin.get(ch);
    }
    cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return 0;
}
如果输入如下，该程序将打印什么内容？
I see a q<Enter>
I see a q<Enter>
其中，<Enter>表示按回车键

9、下面的两条语句都读取并丢弃行尾之前的所有字符（包括行尾）。这两条语句的行为在哪方面不同？
while (cin.get() != '\n')
    continue;
cin.ignore(80, '\n');
ignore只能读取并丢弃输入流中的80个字符，多出来的无法丢弃，而while(cin.get()!='\n)continue;可以
一直读取丢弃直到遇到换行符

*/
