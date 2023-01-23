// swaping with reference and with pointers
#include <iostream>
void swapr(int &a, int &b); // a,b are aliases for ints
void swapp(int * p,int * q); // p,q are address of ints
void swapv(int a, int b); // a,b are new variables
int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using reference to swap contents: \n";
    swapr(wallet1,wallet2); // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again: \n";
    swapp(&wallet1,&wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1,wallet2); // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    return 0;
}

void swapr(int &a, int &b)
{
    int temp;

    temp =a;
    a = b;
    b = temp;
}

void swapp(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a,int b) // 函数体中的变量只是复制了参数的值，是不同的对象
{
    int temp;
    temp = a;
    a = b;
    b = temp;
} 