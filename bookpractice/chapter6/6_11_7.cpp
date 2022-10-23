#include <iostream>
#include <cctype>
#include <cstring>
int main()
{
    using namespace std;
    int vowels_num=0,consonants_num = 0,others_num = 0;
    char word[50];
    cout << "Enter words (q to quit): " << endl;
    cin >> word;
    while (strcmp(word,"q")) //同为字符串才能比较,相同为0即false,不同非0即为True
    {
        if (isalpha(word[0]))
        {
            if ((word[0] == 'a')||(word[0] == 'e')||(word[0] == 'i')||(word[0] == 'o')||(word[0] == 'u'))
                vowels_num++;
            else 
                consonants_num++;
        }
        else 
            others_num++;
        cin.clear(); 
        cin >> word;
    }
    cout << vowels_num << " words beginning with vowels " << endl;
    cout << consonants_num << " words beginning with consonants " << endl;
    cout << others_num << " others";
    return 0;
}