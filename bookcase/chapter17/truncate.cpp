// using get() to truncate input line , if necessary 
#include <iostream>

const int SLEN = 10;
inline void eatline() {while (std::cin.get() != '\n') continue; } // 读取并丢弃该行中余下的内容，cin.get(void)返回的是字符编码int值

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[SLEN];
    char title[SLEN];
    cout << "Enter your name: ";
    cin.get(name, SLEN);

    if (cin.peek() != '\n') // 下一个输入不是换行符
        cout << "Sorry, we only have enough room for "
             << name << endl;
    eatline(); // 舍弃余下的输入
    cout << "Dear " << name << ", enter your title: \n";
    cin.get(title, SLEN);
    if (cin.peek() != '\n')
        cout << "We have forced to truncate your title.\n";
    eatline();
    cout << " Name: " << name
         << "\nTitle: " << title << endl;

    return 0;
}