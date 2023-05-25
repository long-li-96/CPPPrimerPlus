// 从文件中读取单词（>>），其中单词用空格、制表符、换行符隔开，并使用vector<string>对象存储
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // for_each的库

bool judgePalindrome(const std::string & str1) noexcept;
void Show(const std::string & str);

int main()
{
    std::vector<std::string> StrVector;
    std::string TemparyStr;
    std::ifstream inFile;
    std::string filePath = "/Users/kali/Desktop/projects/c:c++/CaddaddPrimerPlus/testfile/16_10_3.txt";

    inFile.open(filePath);
    if (!inFile.is_open())
    {
        std::cout << "Could not open the file " << filePath << std::endl;
        std::cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    while (inFile.good() && !inFile.eof())
    {
        inFile >> TemparyStr;
        StrVector.push_back(TemparyStr);
        inFile.get();
    }

    std::for_each(StrVector.begin(), StrVector.end(), Show);


    return 0;
}

bool judgePalindrome(const std::string & str1) noexcept
{
    std::string str2; // 初始化一个与str1大小相同的全是空格的字符串
    std::copy(str1.rbegin(), str1.rend(), std::back_inserter(str2)); // 从后插入str2
    if (str2 == str1)
        return true;
    // const_iterator防止元素被更改
    for (std::string::const_iterator i = str1.begin(), j = str2.begin(); i != str1.end(); i++, j++)
    {
        if (isalpha(*i) && isalpha(*j))
        {
            if (tolower(*i) != tolower(*j))
                return false;
        }
        else if (*i != *j)
            return false;
    }
    return true;
}

void Show(const std::string & str) // 使用const可以使Show接受常量字符串作为实参
{
    std::cout << str;
    if (judgePalindrome(str))
        std::cout << " is palindrome string!\n";
    else
        printf(" is not palindrom!\n");
}