// Stack1 member functions
#include <iostream>
#include "10_10_5.h"
Stack1::Stack1()
{
    top = 0;
}

bool Stack1::isempty() const
{
    return top == 0;
}

bool Stack1::isfull() const
{
    return top == MAX;
}

bool Stack1::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else 
        return false;
}

bool Stack1::pop(Item & item)
{
    static double sum = 0.0;
    if (top > 0)
    {
        sum += item.payment;
        std::cout << "An order has been processed, current revenue: " << sum << "\n";
        item = items[--top];
        return true;

    }
    else 
        return false;
}