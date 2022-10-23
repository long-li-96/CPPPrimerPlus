#include <iostream>
#include <cctype> // prototypes for character functions
#include <string>
using namespace std;
void Upper(string & str);

int main()
{
    string str1;
    cout << "Enter a string(q to quit): ";
    while(getline(cin,str1))
    {
        if (str1 == "q")
            break;
        Upper(str1);
        cout << "The string now is uppered: " << str1 << endl;
        cout << "Next string(q to quit): ";
    }
    return 0;
}

void Upper(string & str)
{
    int len = str.size();
    int i = 0;
    while (i<len)
    {
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);
        i++;
    }
}