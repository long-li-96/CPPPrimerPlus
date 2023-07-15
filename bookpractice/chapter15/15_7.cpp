/*
1、友元
a、class snap 
{
    friend class clasp;
    ...
};
b、前向声明
class muff; // forwad delaration
class cuff
{
    public:
        void snip(muff &) {...}
        ...
};
class muff
{
    friend void cuff::snip(muff & );
    ...
};
c、cuff类声明应在muff类前，以便编译器理解cuff::snip()。需要前向
声明以使编译器理解snip(muff &)
class muff; // forwad declaration
class cuff 
{
    public:
        void snip(muff &) {...}
        ...
};
class muff
{
    friend void cuff::snip(muff&);
    ...
};

2、能否创建类B只有部份成员是类A的友元，而类A只有部份成员是类B得友元吗？
不能，为使类A拥有一个本身为类B的成员函数的友元，B的声明必须位于A的声明之前
。一个前向声明是不够的，因为这种声明可以告诉A：B是一个类，但它不能指出
类成员的名称。同样，如果B拥有一个本身是A的成员函数的友元，则A的这个声明
必须位于B的声明之前，这两个要求是互斥的

3、下面的嵌套类声明中可能存在什么问题？
class Ribs
{
    private:
        class Sauce
        {
            int soy;
            int sugar;
            public:
                Sauce(int s1, int s2) : soy(s1), sugar(s2) { }
        };
        ...
}
访问类的唯一方法是通过其公有接口，这意味着对于Sauce对象，只能调用构造
函数来创建一个。其他成员（soy和sugar）在默认情况下是私有的，Ribs类访问不到

4、throw和return的区别
假设函数f1()调用函数f2()。f2()中的返回语句导致程序执行在函数f1()中调用
f2()后面的一条语句。throw语句导致程序沿函数调用的当前序列回溯，直到找到
直接或间接包含对f2()的调用的try语句为止。它可能在f1()中、调用f1()的函数中
或其他函数中。找到这样的try语句后，将执行下一个匹配的catch语句，而不是函数
调用后的语句。

5、假设有一个从异常基类派生来的异常类层次结构，则按什么样的顺序放置catch
块？
应按从子孙到祖先的顺序排列catch语句

6、对于Grand、Superb和Maganificent类，假设pg为Grand * 指针，并将其中某个类的对象的地址赋给了它，
而ps为Superb *指针，则下面两个代码示例的行为有什么不同？
#1 if (ps = dynamic_cast<Superb *> (pg))
    ps->say();
#2 if (typeid(*pg) == typeid(Superb))
    ((Superb *) pg)->say();
//////////////////////////////////
class Grand
{
    private:
        int hold;
    public:
        Grand(int h = 0): hold(h) {}
        virtual void Speak() const { cout << "I am a grand class!\n"}
        virtual int Value() const { return hold; }
};
class Superb: public Grand
{
    public:
        Superb(int h = 0) : Grand(h) {}
        void Speak() const {cout << "I am a superb class!!\n"}
        virtual void Say() const
        {cout << "I hold the superb value of " << Value() << "!\n";}
}
class Magnificent: public Superb
{
    private:
        char ch;
    public:
        Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
        void Speak() const {cout << "I am a magnificent class!!!\n"}
        void Say() const {cout << "I hold the character " << ch << 
        " and the integer " << Value() << "!\n";}
}
对于示例#1，如果pg指向一个Superb对象或从Superb派生而来的任何类的对象，则if条件为true，具体地说，如果
pg指向Magnificent对象，则if条件也为true。
对于示例#2，仅当指向Superb对象时，if条件才为true，如果指向的是从Superb派生出来的对象，则if条件为false。

7、static_cast运算符与dynamic_cast运算符有什么不同？
dynamic_cast运算符只允许沿类层次结构向上转换，而static_cast运算符
允许向上转换和向下转换。static_cast运算符还允许枚举类型和整型之间以及
数值类型之间的转换。




*/