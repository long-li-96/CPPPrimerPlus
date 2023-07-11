/*
1、以A栏的类为基类时，B栏的类采用公有派生还是私有派生更合适
A                               B
class Bear                      class PolarBear // 公有
class Kitchen                   class Home      // 私有
class Person                    class Programer // 公有
class Person                    class HorseAndJockey // 私有
class Person class Automabile   class Driver // 人公有，汽车私有

2、有下面定义：
class Frabjous 
{
    private:
        char fab[20];
    public:
        Frabjous(const char * s = "C++") : fab(s) {}
        virtual void tell() {cout << fab;}
};
class Gloam
{
    private:
        int glip;
        frabjous fb;
    public:
        Gloam(int g = 0, const char * s = "C++");
        Gloam(int g, const Frabjous & f);
        void tell();
};
Gloam::Gloam(int g, const char * s):glip(g), fb(s) {}
Gloam::Gloam(int g, const Frabjous & f): glip(g), fb(f) {}
void Gloam::tell()
{
    fb.tell();
    cout << glip << endl;
}

3、有下面的定义：
class Frabjous
{
    private:
        char fab[20];
    public:
        Frabjous(const char * s = "C++"): fab(s) {}
        virtual void tell() {cout << fab;}
};
class Gloam : private Frabjous
{
    private:
        int glip;
    public:
        Gloam(int g = 0, const char * s = "C++");
        Gloam(int g, const Frabjous & f);
        void tell();
};
Gloam::Gloam(int g, const char * s)
            : glip (g), Frabjous(s) {}
Gloam::Gloam(int g, const Frabjous & f)
            : glip(g), Frabjous(f) {}
void Gloam::tell()
{
    Frabjous::tell();
    cout << glip << endl;
}

4、有下面的定义，基于Stack模板和Worker类的：
Stack<Worker *> sw;
写出将生成的类声明，只实现类声明，不实现非内联类方法。
class Stack<Worker *>
{
    private:
        enum {MAX = 10};
        Worker * items[MAX];
        int top;
    public:
        Stack();
        Boolean isempty();
        Boolean isfull();
        Boolean push(const Worker * & item);
        Boolean pop(Worker * & item);
};

5、使用模板定义对下面内容进行定义：
string对象数组；
ArrayTP<string> sa;
double数组栈；
StackTP< Array<double> > stck_arr_db;
指向Worker对象的指针的栈数组。
ArrayTP< StackTP<Worker *> > arr_stk_wpr;

6、指出虚基类于非虚基类的区别
如果两条继承路线有相同的祖先，则类中将包含祖先成员的两个拷贝。将祖先类作为虚基类可以解决这种问题。
*/