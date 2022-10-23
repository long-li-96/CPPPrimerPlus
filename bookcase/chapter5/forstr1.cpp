#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i = word.size() - 1;i >= 0; i --)
        cout << word[i];
    return 0;
}