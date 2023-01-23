#include <iostream>
#include <cstring> // for strlen()
using namespace std;

template <typename T>
T maxn(T ar[], int n);

template <> char * maxn<char *>(char * str[], int n); // 字符串数组
//显示具体化的特征标要与模板保持一致 显示实例化：template char * maxn<char *>(char * str[], int n)

int main()
{
    int intnum[6] = {1,2,4,5,3,0};
    double dounum[4] = {1.1,2.2,3.3,0.1};
    cout << "The max of intnum is: " << maxn(intnum, 6) << endl;
    cout << "The max of dounum is: " << maxn(dounum, 4) << endl;
    char * str1[5] = {"abc","C++","tester","developer","home"};
    cout << "The max of str1 is: " << maxn(str1,5);
    return 0;
}

template <typename T>
T maxn(T ar[],int n)
{
    T temp = ar[0];
    for (int i = 1; i < n; i ++)
    {
        if (temp < ar[i])
            temp = ar[i];
    }
    return temp;
}

template <> char * maxn<char *>(char * str[],int n)
{
    char * strt = str[0];
    for (int i = 1; i < n; i ++)
    {
        if (strlen(strt) < strlen(str[i]))
            strt = str[i];
    }
    return strt;
}
