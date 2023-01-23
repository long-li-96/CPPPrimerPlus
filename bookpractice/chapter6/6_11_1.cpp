#include <iostream>
#include <cctype>
int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @ to terminate input.\n";
    char ch;
    while ((ch = cin.get()) != '@') // 直接在while条件中输入并判断
    {
        if (isdigit(ch))
            continue;
        else if (islower(ch))
        {
            ch = toupper(ch); // <cctype> std::toupper
            cout << ch;
        }
        else if (isupper(ch))
        {
            ch = tolower(ch);
            cout << ch;
        }
        else 
            cout << ch;
    }
    return 0;
}