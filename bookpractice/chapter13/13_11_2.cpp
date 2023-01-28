#include <iostream>
#include <cstring>
#include "13_11_2.h"

// Cd methods
Cd::Cd(char const * s1, char const * s2, int n, double x)
{
    performers = new char[std::strlen(s1) + 1];
    std::strcpy(performers, s1);
    label = new char[std::strlen(s2) + 1];
    std::strcpy(label, s2);
    if (n < 0)
        n = 0;
    selections = n;
    if (x < 0)
        x = 0.0;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std:strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
// 初始化列表
Cd::Cd(): selections(0), playtime(0.0)
{
    performers = new char[5];
    std::strcpy(performers, "None");
    performers[4] = '\0';
    label = new char[5];
    std::strcpy(label, "None");
    label[4] = '\0';
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    std::cout << "performers: " << performers << std::endl;
    std::cout << "label: " << label << std::endl;
    std::cout << "selections: " << selections << std::endl;
    std::cout << "playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == & d)
        return * this;
    delete [] performers;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    delete [] label;
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return * this;
}

// Classic methods
Classic::Classic(char const * s1, char const * s2, char const * s3, int n, double x):
                Cd(s2, s3, n, x)
{
    major_works = new char[std::strlen(s1) + 1]; // 多出的'\0'也即Null
    std::strcpy(major_works, s1);
}

Classic::Classic(char const * s1, const Cd & d): Cd(d)
{
    major_works = new char[std::strlen(s1) + 1]; // 多出的'\0'也即Null
    std::strcpy(major_works, s1);
}

Classic::Classic(const Classic & c): Cd(c) // 调用基类的复制构造函数
{
    major_works = new char[std::strlen(c.major_works) + 1];
    std::strcpy(major_works, c.major_works);
}

Classic::Classic():Cd()
{
    major_works = new char[5];
    std::strcpy(major_works, "None");
    major_works[4] = '\0'; 
}

Classic::~Classic()
{
    delete [] major_works;
}

void Classic::Report() const
{
    Cd::Report(); // 在派生类直接调用基类方法，默认调用方法的对象为当前派生类的对象
    std::cout << "major_works: " << major_works << std::endl;
}

Classic & Classic::operator=(const Classic &c)
{
    if (this == & c) // 地址相等
        return * this;
    Cd::operator=(c); // copy base portion
    delete [] major_works;
    major_works = new char[std::strlen(c.major_works) + 1];
    std::strcpy(major_works, c.major_works);
    return * this;
}