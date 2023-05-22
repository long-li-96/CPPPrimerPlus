// 简单判断回文数，不考虑字符、大小写
// 使用字符串方法
#include <iostream>
#include <string>
#include <algorithm>
bool JudgePalindrome(std::string & str1) noexcept;

int main()
{
    std::string str1 = "123121";
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

