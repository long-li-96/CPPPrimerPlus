// using a static local variable
#include <iostream>
// constants
const int ArSize = 10;
void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while(cin) // 空白输入结束
    {
        cin.get(next);
        while (next != '\n') // string didn't fit! 换行符之后还有输入,被next捕获
            cin.get(next); // dispose of remainder 一直捕获并舍弃
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << str << "\" contains ";
    while(* str ++)         // go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}