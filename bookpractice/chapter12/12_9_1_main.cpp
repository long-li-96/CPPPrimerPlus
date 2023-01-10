// using class Cow
#include "12_9_1.h"
using std::cin;
const int MaxLen = 81;

int main()
{
    Cow littlecow;
    littlecow.ShowCow();

    char name[MaxLen], hobby[MaxLen];
    double weight;
    
    cin.get(name, MaxLen);
    while (cin && cin.get() != '\n') // cin是首先验证cin.get()合法性，获取cin缓冲区所有字符直至捕获换行符跳出这个while循环
        continue;
    if (!cin || name[0] == '\0') // 非法输入或空行退出程序
        return 0;

    cin.get(hobby, MaxLen);
    while (cin && cin.get() != '\n')
        continue;
    if (!cin || name[0] == '\0')
        return 0;

    cin >> weight;
    
    Cow bigcow(name, hobby, weight);
    bigcow.ShowCow();

    Cow middlecow;
    middlecow = bigcow;
    middlecow.ShowCow();

    Cow smallcow(middlecow);
    smallcow.ShowCow();

    return 0;
}
