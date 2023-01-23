#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string str;
    int sum = 0;
    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> str;
    while (str != "done") // string类可以直接比较
    {
        sum += 1;
        cin >> str;
    }
    cout << "You entered a total of " << sum << " words.";
    return 0;
}