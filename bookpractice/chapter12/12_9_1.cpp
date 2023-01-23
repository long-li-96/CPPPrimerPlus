#include "12_9_1.h"
using std::cout;
using std::endl;

Cow::Cow()
{
    hobby = new char[1];
    name[0] = hobby[0] = '\0';
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::strncpy(name, nm, 20); // 将字符串nm指定长度20复制到name，防止栈空间溢出导致程序崩溃
    int ho_len = std::strlen(ho);
    hobby = new char[ho_len + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name, c.name);
    int ho_len = std::strlen(c.hobby);
    hobby = new char[ho_len + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
    hobby = NULL; // 将hobby置为空指针
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)
        return * this;
    delete [] hobby;
    int ho_len = std::strlen(c.hobby);
    hobby = new char[ho_len + 1];
    std::strcpy(hobby, c.hobby);
    std::strcpy(name, c.name);
    weight = c.weight;
    return * this;
}

void Cow::ShowCow() const
{
    cout << name << " " << hobby << " " << weight << endl;
}