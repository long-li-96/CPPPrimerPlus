// some type combinations 结合体
#include <iostream>
struct antarctica_year_end
{
    int year;
    /* some really interesting data, etc. */
};

int main()
{
    antarctica_year_end s01, s02, s03; // create some structures
    s01.year = 1998;
    antarctica_year_end * pa = &s02;
    pa->year = 1999;
    antarctica_year_end trio[3]; // arrays of 3 structures
    trio[0].year = 2003;
    std::cout << trio->year << std::endl;
    const antarctica_year_end * arp[3] = {&s01, &s02, &s03}; // 为指针数组元素分别赋值结构变量地址
    std::cout << arp[1]->year << std::endl;
    const antarctica_year_end ** ppa = arp; // 指向结构数组指针的指针赋值
    auto ppb = arp; // C++11 automatic type deduction 推理
    // or else use const antarctica_years_end ** ppb = arp;
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb+1))->year << std::endl;
    return 0; 
}