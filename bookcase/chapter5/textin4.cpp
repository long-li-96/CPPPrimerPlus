// reading chars with cin.get()
#include <iostream>
int main()
{
    using namespace std;
    int ch;
    int count = 0;

    while ((ch = cin.get()) != EOF) // End of File
    {
        cout.put(char(ch)); // 输出单个字符
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;
}