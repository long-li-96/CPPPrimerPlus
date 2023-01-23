// revesing an array
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    cout << word << endl;

    // physically modify string object
    char temp;
    int i, j;
    for (j = 0, i = word.size() - 1; j < i; -- i, ++ j) // 数组倒序，数组从两端同时遍历，交换值
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone\n";
    return 0;
}

// cin 输入 string 遇到空格、换行，即字符串输入结束