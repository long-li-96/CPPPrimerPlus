// some istream methods
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    // read and echo input up to a # character
    char ch;

    while (cin.get(ch)) // terminate on EOF 从键盘模拟文件尾将终止循环
    {
        if (ch != '#')
            cout << ch;
        else 
        {
            cin.putback(ch); // reinsert character 将#放入到输入流中
            break;
        }
    }

    if (!cin.eof())
    {
        cin.get(ch); // 读取插入的#到ch中
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#') // look ahead 返回下一个字符，但不抽取这个字符
    {
        cin.get(ch);
        cout << ch;
    }

    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else 
        cout << "End of file reached.\n";
    return 0;
}