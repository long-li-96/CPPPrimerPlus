#include <iostream>
#include <string>
const double increase = 0.1;
const double initialV = 100;
const double finalV = 10000;
int main()
{
    double balance = initialV;
    int i = 0;
    for (; balance < finalV; i++)
        balance *= 1+increase;
    std::cout << i << std::endl;
    // std::string str1 = "test";
    // std::cin >> str1;
    // std::cout << str1;
    int j = 1;
    std::cin >> j;
    std::cout << j << std::endl;
}