// 判断回文数，考虑大小写、空格、特殊字符
// 使用STL函数
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool JudgePalindrome(std::string & str1) noexcept;

int main()
{
    std::string str1 = "A123,321a";
    if (JudgePalindrome(str1))
        std::cout << "It's palindrome string!\n";
    else
        printf("It' not palindrome!\n");
    return 0;
}

bool JudgePalindrome(std::string & str1) noexcept
{
    std::string str2 = str1;
    std::reverse(str2.begin(), str2.end()); // 翻转字符串，就地算法返回void
    if (str1 == str2)
        return true;
    return false;
}

