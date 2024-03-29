// string function with a default argument
#include <iostream>
const int ArSize = 80;
char * left(const char * str,int n = 1);
int main()
{
    using namespace std;
    char sample[ArSize];
    cout << "Enter a string: " << endl;
    cin.get(sample, ArSize);
    char * ps = left(sample, 4);
    cout << ps << "\n";
    delete [] ps; // free old string
    ps = left(sample);
    cout << ps << "\n";
    delete [] ps; // free new string
    return 0; 
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char * left(const char * str, int n)
{
    if(n<0)
        n = 0;
    char * p = new char[n+1]; // new一个字符串
    int i;
    for (int i = 0; i < n && str[i]; i++) // str[i] != '\0'
        p[i] = str[i]; // copy characters 最基本的数据类型赋值
    while (i<=n)
        p[i++] = '\0'; // set rest of string to '\0'
        
    return p;
}