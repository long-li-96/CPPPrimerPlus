// Stack member function
#include "stack.h"
Stack::Stack() // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const 
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top ++] = item;
        return true;
    }
    else 
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[-- top]; // 只是用item记录被推出的元素
        return true;
    }
    else 
        return false;
}