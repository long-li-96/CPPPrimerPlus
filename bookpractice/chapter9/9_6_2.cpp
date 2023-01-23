// using string instead of char array
// static.cpp -- using a static local variable
// constants
#include <iostream>
#include <string>
using namespace std;
// function prototype
void strcount(const string str);

int main()
{
    string input;
    
    cout << "Enter a line:\n";
    getline(cin, input);
    while(cin) // 输入非空
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin,input); 
        if (input == "")
            break;
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const string str)
{
    static int total = 0; // static local variable 静态变量用来给函数调用等计数
    int count = 0;

    cout << "\"" << str << "\"contains ";
    count = str.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}