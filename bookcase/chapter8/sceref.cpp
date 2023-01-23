// defining and using a reference
#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;
    int & rodents = rats; // rodents is a reference

    cout << "rats = " << rats;
    cout << ",rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ",rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies; // can we change the reference?
    cout << "bunnies = " << bunnies;
    cout << ",rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    cout << "bunnies address = " << &bunnies;
    cout << ",rodents address = " << &rodents << endl;

    return 0;
}

// 引用只能在声明时初始化，不能赋值，引用一旦初始化指向某个变量，便会一直绑定这个变量，无法改变