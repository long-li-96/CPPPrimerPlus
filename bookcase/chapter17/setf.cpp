// using setf() to control formatting
// setf()的第一个函数原型,使用setf()控制输出
// fmtflags setf(fmtflags)
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;
    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos); // show plus sign 正数前面加上+
    cout << temperature << endl;

    cout << "For our programming friends, that's \n";
    cout << std::hex << temperature << endl; // use hex
    cout.setf(ios_base:: uppercase); // use uppercase in hex 十六进制输出使用大写字母
    cout.setf(ios_base::showbase) ; // use OX perfix for hex 使用c++基数前缀(0, 0x)
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha); // 输出bool值，输入同
    cout << true << "!\n";

    return 0;
}