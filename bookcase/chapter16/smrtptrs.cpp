// 使用new、new[]，可以使用unique_ptr, new[]不能和shared_ptr用

/*
using three kinds of smart pointers
requires support of C++11 shared_ptr and unique_ptr
unique_ptr不允许unique_ptr对象之间进行赋值
unique ptr<string> p3 (new string ("auto"); unique ptr<string> p4; p4 = р3; 非法代码
但是允许右值为一个临时的值
1
unique ptr<string> pu3;
pu3 = unique ptr<string> (new string "Yo!");
2
unique_ ptr<string> demo (const char * s){
unique ptrestring> temp (new string(s));
return temp;}
unique_ptr<string> ps;
ps = demo ("Uniquely special");
*/

/* 将 一个unique_ptr赋给另一个
unique_ptrcstring» ps1, ps2;
ps1 = demo ("Uniquely special");
ps2 = move (ps1) ;
psi = demo (" and more");
*/

/* 
unique_ptr‹ string> pu1 (new string "Hi ho!");
unique_ptr‹ string> pu2;
pu2 = pu1; // 悬挂指针,编译报错
*/
#include <iostream>
#include <string>
#include <memory>

class Report
{
    private:
        std::string str;
    public:
        Report(const std::string & s) : str(s)
        {std::cout << "Object created!\n";}
        ~Report() {std::cout << "Object deleted!\n";}
        void comment() const { std::cout << str << std::endl;}
};

int main()
{
    {
        // std命令空间没有这个成员auto_ptr
        // std::auto_ptr<Report> ps (new Report("using auto_ptr"));
        // ps->comment(); // use -> to invoke a member function
    }

    {
        std::shared_ptr<Report> ps (new Report("Using shared_ptr"));
        ps->comment();
    }

    {
        std::unique_ptr<Report> ps (new Report("Using unique_ptr"));
        ps->comment();
    }
    return 0;
}