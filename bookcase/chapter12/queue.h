// interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// this queue will contain Customer items
class Customer
{
    private:
        long arrive; // arrival time for customer
        int processtime; // processing time for customer
    public:
        Customer() {arrive = processtime = 0;}
        void set(long when); // set arrival=processtime=when
        long when() const {return arrive;}
        int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue
{
    private:
        // class scope definitions
        // Node is a nested structure definition local to this class
        struct Node {Item item; struct Node * next;}; // next是指向Node的指针
        enum {Q_SIZE = 10};
        // private class members
        Node * front; // pointer to front of Queue
        Node * rear; // pointer to rear of Queue
        int items; // current number of items in Queue
        const int qsize; // maximum number of items in Queue
        // preemptive definitions to prevent public copying
        Queue(const Queue & q): qsize(0) {} // 复制构造函数
        Queue & operator=(const Queue & q) {return *this;} // 赋值运算符
    public:
        Queue(int qs = Q_SIZE); // create queue with a qs limit
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item & item); // add item to end;
        bool dequeue(Item & item); // remove item from front
};       

#endif