/*
1、什么是类？
类是用户定义的类型的定义。类声明指定了数据如何存储，同时指定了用来访问和操纵这些数据的方法（类成员函数）。

2、类如何实现抽象、封装和数据隐藏？
类表示人们可以类方法的公有接口对类对象执行的操作，这是抽象。类的数据成员可以是私有的（默认值），这意味着
只能通过成员函数来访问这些数据，这是数据隐藏。

3、对象和类之间的关系是什么？
类定义了一种类型，包括如何使用它。对象是一个变量或其他数据对象（如由new生成的），并根据类定义被创建和使用。类
和对象之间的关系同标准类型与其变量之间的关系相同

4、除了是函数之外，类函数成员与类数据成员之间的区别是什么？
如果创建给定类的多个对象，则每个对象都有自己的数据内存空间，但所有的对象都使用同一组成员函数（通常方法是公有的，
而数据是私有的）

5、定义一个类来表示银行账户。数据成员包括储户姓名、账号（使用字符串）和存款。成员函数执行如下操作：
创建一个对象并将其初始化；
显示储户姓名、账号和存款；
存入参数指定的存款；
取出参数指定的款项。
请提供类声明
#include <cstring>
class BankAccount
{
    private:
        std::string name;
        std::string acctnum;
        double balance;
    public:
        BankAccount(const std::string & client, const std::string & num, double bal = 0.0);
        void show(void) const;
        void deposit(double cash);
        void withdraw(double cash);
};

6、类构造函数何时被调用？类析构函数呢？
在创建类对象或显式调用构造函数时，类的析构函数都将被调用。当对象过期时，类的析构函数将被调用。

7、给出5中银行账户类的构造函数的代码。
默认参数应位于原型中，而不是函数定义中
// char数组版
BankAccount::BankAccount(const char * client, const char * num, double bal)
{
    strncpy(name, client, 39);
    name[39] = '\0';
    strncpy(acctnum, num, 24);
    acctnum[24] = '\0';
    balance = bal;
}

8、什么是默认构造函数。拥有默认构造函数有何好处？
默认构造函数是没有参数或所有参数都有默认值的构造函数。拥有默认构造函数后，可以声明对象而不初始化它，即使
已经定义了初始化构造函数。它还使得能够声明数组。

9、修改stock20.h中的Stock类的定义，使之包含返回各个数据成员值的成员函数。注意：返回公司名的成员函数不应为
修改数组提供便利，也就是说，不能简单返回string引用。
// stock30.h
#ifndef STOCK30_H_
#define STOCK30_H_
class Stock
{
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        Stock(); // default constructor
        Stock(const std::string & co, long n, double pr);
        ~Stock() {} // do-nothing destructor
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;
        const Stock & topval(const Stock & s) const;
        int numshares() const {return shares; }
        double shareval() const {return share_val; }
        double totalval() const {return total_val; }
        const string & co_name() const { return company;}
};

10、this和*this是什么？
this指针是类方法可以使用的指针，它指向用于调用方法的对象。因此，this是对象的地址，*this是对象本身。

*/