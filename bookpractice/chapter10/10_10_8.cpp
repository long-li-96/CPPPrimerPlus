#include <iostream>
#include "10_10_8.h"

List::List()
{
    tail = 0;
}

bool List::append(Item item)
{
    if (tail < SIZE)
    {
        list[tail ++] = item;
        return true;
    }
    return false;
}

bool List::is_empty() const
{
    return tail == 0;
}

bool List::is_full() const
{
    return tail == SIZE;
}

void List::visit(void (* pf) (Item &)) // 函数指针
{
    for (int i = 0;i < tail; i ++)
        pf(list[i]);
}

void List::show() const 
{
    using std::cout;
    for (int i = 0; i < tail; i ++)
    {
        cout << list[i] << " ";
    }
    cout << "\n";
}