/*
1、假设String类有如下私有成员：
class String
{
    private:
        char * str; // points to string allocated by new
        int len; // holds length of string
    ...
};
a、下述默认构造函数有什么问题？
String::String() {}
语法是正确的，但该构造函数没有将str指针初始化。该构造函数应将指针设置成NULL或使用new[]来初始化它
b、下述构造函数有什么问题？
String::String(const char * s)
{
    str = s;
    len = strlen(s);
}
类中str只是一个指针，没有分配内存，而这个构造函数没有创建新的字符串，而只是复制了原有字符串的地址。应当使用
new[]和strcpy()。
c、下述构造函数有什么问题？
String::String(const char * s)
{
    strcpy(str, s);
    len = strlen(s);
}
复制了字符串，但没有给它分配存储空间，应使用new char[len + 1]来分配适当数量的内存。

2、如果定义了一个类，其指针成员是使用new初始化的，请指出可能出现的3个问题以及如何纠正这些问题
（1）当这种类型的对象过期时，对象的成员的指针指向的数据仍将保留在内存中，这将占用空间，同时不可访问，因为
指针已经丢失。可以让类析构函数删除构造函数中的new分配的内存，来解决。
（2）如果将一个对象初始化为另一个对象，析构函数可能试图释放这个内存两次，因为将一个对象初始化为另一个对象的
默认初始化，将复制指针值，但不复制指向的数据，这将使两个指针指向相同的数据。可以定义一个复制构造函数，使初始化
复制指向的数据。
（3）将一个对象赋给另一个对象也将导致两个指针指向相同的数据。可以重载赋值运算符，使之复制数据，而不是指针

3、如果没有显示提供类方法，编译器将自动生成哪些类方法？请描述这些隐式生成的函数的行为。
C++自动提供下面的成员函数：
如果没有定义构造函数，提供默认构造函数
如果没有定义复制构造函数，将提供复制构造函数
如果没有定义赋值运算符，将提供赋值运算符
如果没有定义析构函数，将提供默认析构函数
如果没有定义地址运算符，将提供地址运算符
默认构造函数不完成任何工作，但使得能够声明数组和未初始化的对象，默认复制构造函数和默认赋值运算符使用成员赋值。
默认析构函数也不完成任何工作。隐式地址运算符返回调用对象的地址（this指针的值）

4、类声明
#include <iostream>
#include <cstring>
using namespace std;
class nifty
{
    private:
        char * personality; // create a pointer
        int talents;
    public: // needed
    // methods
        nifty();
        nifty(const char * s);
        nifty(const nifty & n);
        ~nifty(){ delete [] personality; }
        nifty & operator=(const nifty & n) const;
        fiend ostream & operator<<(ostream & os, const nifty & n); // note closing semicolon
};
nifty::nifty()
{
    personality = NULL;
    talents = 0;
}
nifty::nifty(const char * s)
{
    personality = new char [strlen(s) + 1];
    strcpy(personality, s);
    talents = 0;
}
ostream & operator<<(ostream & os, const nifty & n) // 友元：其他类操作这个类的私有数据，这个类放第二个参数
{
    os << n.personality << '\n';
    ost << n.talent << '\n';
    return os;
}

5、对于下面的类声明：
class Golfer
{
    private:
        char * fullname; // points to string containing golfer's name
        int games; // holds number of golf games played
        int * scores; // points to first element of array of golf scores
    public:
        Golfer();
        Golfer(const char * name, int g = 0);
        // creates empty dynamic array of g elements if g > 0
        Golfer(const Golfer & g);
        ~Golfer();
};
a、下列各条语句将调用哪些类方法？
Golfer nancy; // Golfer()
Golfer lulu("Little Lulu"); // Golfer(const char * name, int g)
Golfer roy("Roy Hobbs", 12); // Golfer(const char * name, int g)
Golfer * par = new Golfer; // Golfer()
Golfer next = lulu; // Golfer(const Golfer & g)
Golfer hazzard = "Weed Thwacker"; // Golfer(const char * name, int g)
*par = nancy; // 默认赋值运算符
nancy = "Nancy Putter"; // Golfer(const char * name, int g), then 默认赋值运算符
b、类需要另外几个方法才能更有用，但是类需要哪些方法才能防止数据被损坏呢？
定义一个复制数据（而不是地址）的赋值运算符。

静态类成员函数，不能通过对象调用这个函数，不能使用this指针，只能使用静态数据成员

*/