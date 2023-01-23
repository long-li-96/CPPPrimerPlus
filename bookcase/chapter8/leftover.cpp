// overloading the left() function
#include <iostream>
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str,int n = 1);

int main()
{
    using namespace std;
    const char * trip = "Hawaii!!"; // test value
    unsigned long n = 12345678; // test value
    int i;
    char * temp;

    for(i = 1; i < 10; i ++)
    {
        cout << left(n,i) << endl;
        temp = left(trip,i);
        cout << temp << endl;
        delete [] temp; // point to temporary storage
    }
    return 0;
}

// This function returns the first ct digits of the number num.
// 对数字截取从左开始的指定位数
unsigned long lef(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0; // return 0 if no digits
    while (n /= 10) // 判断n > 10 同时对n进行降位
        digits ++; // 取得n的总位数
    if (digits > ct)
    {
        ct = digits - ct; // ct此时为需要舍弃的右边位数
        while (ct --)
            num /= 10; // num最后为舍弃右边指定位数的数字
        return num; // return left ct digits
    }
    else // if ct >= number of the whole digits
        return num; // return the whole number
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
// 从左开始截取指定长度的字符串
char * left(const char * str,int n)
{
    if (n < 0)
        n = 0;
    char * p = new char[n+1]; // 数据过滤与数据处理分离
    int i;
    for (i = 0;i < n && str[i]; i++)
        p[i] = str[i]; // copy characters
    while (i<=n)
        p[i++] = '\0'; // set rest of string to '\0'
    return p;
}