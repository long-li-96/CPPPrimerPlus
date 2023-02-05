// a stack template
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type> // 模版类
class Stack
{
private:
    enum {MAX=10}; // const specific to class
    Type items[MAX]; // holds stack items
    int top; // index of top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item); // add item to stack
    bool pop(Type & item); 
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item; // top先被[]再++, 兼容了初始top为0即栈无元素的情况
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top]; // top先--再被[]，top最大为max，此时数组最大索引为max-1
        return true;
    }
    else
        return false;
}
// top一直是空的,top-1才是数组中最后一个元素

#endif