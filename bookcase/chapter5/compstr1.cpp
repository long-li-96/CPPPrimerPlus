// comparing strings using arrays
#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char word[5] = "?ate";
    for (char ch = 'a'; strcmp(word,"mate"); ch++) 
    {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;
    return 0;
}

/*
int strcmp(char * str1, char * str2)
{
    for (int i = 0; i < std::strlen(str1); i ++)
    {
        while (!(str1[i] - str2[i]))
            continue;
        return str1[i] - str2[i];
    }
}
*/