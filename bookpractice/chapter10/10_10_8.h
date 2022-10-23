#ifndef LIST_H_
#define LIST_H_
typedef int Item;

class List
{
    private:
        enum {SIZE = 20};
        Item list[SIZE];
        int tail;
    public:
        List();
        bool append(Item item);
        bool is_empty() const;
        bool is_full() const;
        void visit(void (*pf) (Item &));
        void show() const;
};

#endif