// methods for the class Stack
#include "12_9_4.h"

using std::cout;

Stack::Stack(int n)
{
    if (n < 0)
    {
        cout << "Number of size cant't be negative; "
             << "size set to 0.\n";
        size = 0;
    }
    else if (n > MAX)
    {
        cout << "Number of size can't be negative; "
             << "size set to " << MAX << ".\n";
        size = MAX;
    }
    else
    {
        size = n;
    }
    pitems = new Item[size];
    top = size;
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < st.size; i ++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete [] pitems;
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
        pitems[top ++] = item; // 一举两得
        return true;
    }
    else 
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == & st)
        return * this;
    delete [] pitems;
    size = st.size;
    pitems = new Item[size];
    for (int i = 0; i < st.size; i ++)
        pitems[i] = st.pitems[i];
    return *this;
}