// 判断回文数，考虑大小写、空格、特殊字符
// 使用STL函数
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool JudgePalindrome(std::string & str1) noexcept;

int main()
{
    std::string str1 = "b123,321a";
    if (JudgePalindrome(str1))
        std::cout << "It's palindrome string!\n";
    else
        printf("It' not palindrome!\n");
    return 0;
}

bool JudgePalindrome(std::string & str1) noexcept
{
    std::string str2;
    std::copy(str1.rbegin(),str1.rend(), str2.begin());
    if (str2 == str1)
        return true;
    for (std::string::reverse_iterator i = str1.rbegin(),j = str2.rbegin();i != str1.rend(); i++, j++) // c++17可以在一行代码里，连续定义相同类型的变量
    {
        if (isalpha(*i) && isalpha(*j))
        {
            if (tolower(*i) != tolower(*j))
                return false;
        }
        else if (*i !=*j)
            return false;
    }
    return true;
}

