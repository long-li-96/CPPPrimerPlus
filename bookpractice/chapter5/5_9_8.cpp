#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char str[50];
    int sum = 0;
    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> str;
    while (strcmp(str, "done") != 0) // str与done不相等时
    {
        sum += 1;
        cin >> str;
    }
    cout << "You entered a total of " << sum << " words.";
    return 0;
}