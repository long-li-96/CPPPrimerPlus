// using get() and getline()
#include <iostream>

const int Limit = 255;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char input[Limit];
    cout << "Enter a string for getline() processing:\n";
    cin.getline(input, Limit, '#'); // 最多读取输入Limit字符，遇到#舍弃并停止读取输入
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 1\n";

    char ch;
    cin.get(ch); // 读取输入的单字符，遇到换行等分界符停止输入但保留在输入流中
    cout << "The next input character is " << ch << endl;

    if (ch != '\n')
        cin.ignore(Limit, '\n'); // discard rest of line 读取并丢弃接下来的Limit个字符或遇到换行符停止
    
    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#'); // 最多读取Limit字符，遇到#停止读取输入，并将#保留在输入流中
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2\n";

    cin.get(ch); // 读取分界符#
    cout << "The next input character is " << ch << endl;


    return 0;
}