/*
下面是类Cpmv的声明,函数operator+()应创建一个对象，其成员qcode和zcode有操作数的相应成员拼接而成。
请提供为移动构造函数和移动赋值运算符实现移动语义的代码。编写一个使用所有这些方法的程序，为方便测试，
让各个方法都显示特定的内容，以便知道它们被调用。
*/
#include <iostream>
#include <string>
class Cpmv {
 public:
  struct Info {
    std::string qcode;
    std::string zcode;
  };

 private:
  Info *pi;

 public:
  Cpmv();
  Cpmv(std::string q, std::string z);
  Cpmv(const Cpmv &cp);
  Cpmv(Cpmv &&mv);
  ~Cpmv();
  Cpmv &operator=(const Cpmv &cp);
  Cpmv &operator=(Cpmv &&mv);
  Cpmv operator+(const Cpmv &obj) const;
  void Display() const;
};
Cpmv::Cpmv() : pi(nullptr) { std::cout << "Cpmv()\n"; }
Cpmv::Cpmv(std::string q, std::string z) {
  std::cout << "Cpmv(std::string, std::string)\n";
  pi = new Info;  // new创建Info对象，并返回指向它的指针
  pi->qcode = q;
  pi->zcode = z;
}
Cpmv::Cpmv(const Cpmv &cp) { 
    std::cout << "Cpmv(const Cpmv &)\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}
Cpmv::Cpmv(Cpmv && mv)
{
    std::cout << "Cpmv(Cpmv &&)\n";
    pi = mv.pi;
    mv.pi = nullptr;
}
Cpmv::~Cpmv()
{
    std::cout << "~Cpmv()\n";
    delete pi;
}
Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << "operator=(const Cpmv &)\n";
    if (this == &cp)
        return *this;
    if (!cp.pi)
    {
        delete pi;
        pi = cp.pi;
        return *this;
    }
    else if (!pi)
        pi = new Info; // 赋值运算符也需要对指针分配内存
    pi->qcode = cp.pi->qcode; // 需要考虑cp.pi也为nullptr的情况
    pi->zcode = cp.pi->zcode;
    return *this;
}
Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << "operator=(Cpmv &&)\n";
    if (this == &mv)
        return *this;
    if (pi)
        delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    Cpmv cpmv(pi->qcode + obj.pi->qcode, pi->zcode +obj.pi->zcode);
    std::cout << "operator+(const Cpmv &)\n";
    return cpmv;
}
void Cpmv::Display() const
{
    std::cout << "Display()\n";
    if (pi)
        std::cout << "qcode: " << pi->qcode << "\t" << pi->zcode << '\n';
}
int main()
{
    using std::cout;
    Cpmv cp1;
    Cpmv cp2{"q1","z1"}; // 类使用列表初始化
    Cpmv cp3(cp2);
    Cpmv cp4(cp2 + cp3);
    cp1 = cp4;
    Cpmv cp5 = std::move(Cpmv("q5","z5") + Cpmv("q5", "z5")); // 被编译器优化了所以需要std::move()才能调用移动赋值运算符
    cp1.Display();
    cp2.Display();
    cp3.Display();
    cp4.Display();
    cp5.Display();
    return 0;
}