#include <iostream>
#include "10_10_8.h"

void multiply(int & x);

int main()
{
    using std::cout;
    List list1;
    list1.append(2);
    list1.append(5);
    list1.append(9);
    list1.append(0);
    if (list1.is_full())
        cout << "The list is full.\n";
    else 
        cout << "The list is not full.\n";
    list1.show();
    list1.visit(multiply);
    list1.show();
    return 0;
}

void multiply(int & x)
{
    x *= x;
}