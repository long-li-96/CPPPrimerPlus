/* 
an otherwise useless class with move semantics
这个类动态分配内存，并包含常规复制构造函数和移动构造函数，其中移动构造函数使用
了移动语义和右值引用，使用了静态变量来跟踪对象数量。
*/

// 移动构造函数为了实现浅拷贝，移动语义：将一个内存地址绑定的变量改成了其他变量，没有改变内存。
#include <iostream>
using namespace std;

// interface
class Useless
{
    private:
        int n;
        char * pc;
        static int ct; // number to data // 统计类实例化对象个数
        void ShowObeject() const;
    public:
        Useless();
        explicit Useless(int k); // 显式转换方法
        Useless(int k, char ch);
        Useless(const Useless & f); // regular copy constructor
        Useless(Useless && f); // move constructor 移动构造函数
        ~Useless();
        Useless operator+ (const Useless & f) const;
        Useless & operator= (const Useless & f); // copy assignment
        Useless & operator= (Useless && f); // move assignment
        // need operator=() in copy and move versions
        void ShowData() const;
};

// implementation 实现
int Useless::ct = 0; // Useless类的静态变量初始化为0

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObeject();
}

Useless::Useless(int k) : n (k)
{
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObeject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct
         << endl;
    pc = new char [n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObeject(); // 因为这里是构造函数定义里调用类方法，可以直接写
}

Useless::Useless(const Useless & f): n(f.n) // 深复制
{
    ++ct;
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char [n];
    for (int i = 0; i < n; i ++)
        pc[i] = f.pc[i];
    ShowObeject();
}

Useless::Useless(Useless && f) : n (f.n) // 移动构造函数，修改了f对象，所以不能在参数声明中使用const
{
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc; // steal address
    f.pc = nullptr; // give an object nothing in return
    f.n = 0;
    ShowObeject();
}

Useless::~Useless()
{
    cout << "destructor called; object left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObeject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i ++)
        temp.pc[i] = pc[i]; // 临时对象的pc前面部份赋值为调用+的对象的pc值
    for (int i = n; i < temp.n; i ++)
        temp.pc[i] = f.pc[i - n]; // 临时对象的pc后面部份赋值为+后的对象的pc值
    cout << "temp object: \n";
    // temp.ShowObeject();
    cout << "Leaving operator+()\n";
    return temp;
}

Useless & Useless::operator=(const Useless & f)
{
    if (this == &f) // this是调用这个方法的对象的指针
        return *this;
    delete [] pc;
    n = f.n;
    pc = new char [n];
    for ( int i = 0; i < n ; i ++)
        pc [i] = f.pc[i];
    return *this;
}

Useless & Useless::operator=(Useless && f)
{
    if (this == &f) // 对右值取地址
        return *this;
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

void Useless::ShowObeject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void * ) pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(object empty)";
    else 
        for (int i = 0; i < n; i ++)
            cout << pc[i];
    cout << endl;
}

// application
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;
        Useless three(20, 'o');
        // Useless && temp = one + three;
        Useless four (one + three) ; // calls operator+(), move constructor使用移动构造函数, one + three 是一个临时对象也没有名称，也无法通过通过其他表达式访问 是右值
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
}
