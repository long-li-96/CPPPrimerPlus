// using const_cast<>
#include <iostream>

using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000;

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    return 0;
}

// 函数声明中参数是const int *，不能修改指向的int，指针pc被改为int *，但是当传pop2时指向的还是
// 不可修改的对象，所以无法更改
void change(const int * pt, int n)
{
    int * pc;
    pc = const_cast<int *> (pt);
    *pc += n;
}