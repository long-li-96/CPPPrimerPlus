// using setf() with 2 arguments to control formating
// 设置对齐方式
// -lm 选项命令链接程序搜索数学库
// setf()的第二个函数原型，使用setf()控制输出
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    // use left justfication, show the plus , show trailing
    // zeros, with a precision of 3
    cout.setf(ios_base::left, ios_base::adjustfield); // 左对齐
    cout.setf(ios_base::showpos); // 正数前面加上+
    cout.setf(ios_base::showpoint); // 打印末尾的0和小数点
    cout.precision(3); // 设置精度为3位

    // use e-notation and save old format setting
    // 精度为3的科学默认，显示小数3位
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "Left Justification:\n";
    long n; 
    for (n = 1; n <= 41; n+=10)
    {
        cout.width(4); // 设置输出字段宽度
        cout << n << "|";
        cout.width(12);
        cout<<sqrt(double(n)) << "|\n";
    }

    // change to internal justification
    cout.setf(ios_base::internal, ios_base::adjustfield);
    // restore default floating-point display style
    // 设为默认的浮点显示
    cout.setf(old, ios_base::floatfield);

    cout << "Internal Justification:\n";
    for (n = 1; n <= 41; n+=10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double (n)) << "|\n";
    }

    // use right justification, fixed notation 定点模式
    // 精度为3，在定点模式下显示小数3位
    cout.setf(ios_base::right, ios_base::adjustfield); // 右对齐
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置浮点数定点显示
    cout << "Right Justification:\n";
    for (n = 1; n <= 41; n +=10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout<<sqrt(double (n)) << "|\n";
    }
    
    return 0;
}
// 没有专门指定默认浮点显示的标记
// void unsetf(fmtflags mask) 将位恢复为0，消除调用setf()的效果
// 启用默认浮点数显示模式 
// (1) cout.setf(0, ios_base::floatfield);
// (2) cout.unsetf(ios_base::floatfield);