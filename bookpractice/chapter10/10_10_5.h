// class definition for the stack1 ADT
#ifndef STACK1_H_
#define STACK1_H_

struct customer {
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack1
{
    private:
        enum {MAX = 10};
        Item items[MAX];
        int top;
    public:
        Stack1();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & item);
};

#endif