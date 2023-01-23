#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i = word.size() - 1;i >= 0; i --) // string.size() 返回无符号整数
        cout << word[i];
    return 0;
}