// 计算输入流中第一个$之前的字符数目，将$留在输入流中
// cin.get()、cin.peek()
// cin.get(void)每次只能读取输入流中的一个字符

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char ch;
    int num = 0;

    while (cin.peek()!='$') // 返回输入的下一个字符，但不从输入流中抽取这个字符
    {
        num ++;
        cin.get(ch);
    }
    cout << "The number of input character before first $ is "
         << num << endl;
    cin.get(ch); // 将输入流中的$读取到ch
    cout << "The character in stream is: " << ch << endl;
    return 0;
}