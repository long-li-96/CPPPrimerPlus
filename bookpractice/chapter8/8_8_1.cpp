#include <iostream>
using namespace std;

// 定义一个全局变量，来记录函数被调用的次数
unsigned int call_num = 0;
const unsigned Size = 127;

// 函数原型，第二个参数设置为默认参数0
void print_str(char * str, int n = 0);

int main()
{
    char str[Size];
    cout << "Please enter a string: ";
    cin.get(str,Size);
    for (int i = 0;i<5;i++)
    {
        cout << "When i = " << i << ":\n";
        print_str(str,i);
    }
    cout << "When the second parameter is not entered: \n";
    print_str(str);
    return 0;
}

void print_str(char * str,int n)
{
    call_num++;
    if (n == 0)
        cout << str << endl;
    else 
    {
        for (int i = 0;i<call_num;i++)
            cout << str << endl;
    }
}