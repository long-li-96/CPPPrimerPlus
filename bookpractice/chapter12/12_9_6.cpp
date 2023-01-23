// Queue and Customer methods
#include "12_9_6.h"
#include <cstdlib> // (or stdlib.h) for rand()

// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL; // or nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)
    {
        temp = front; // save address of front item
        front = front->next; // reset pointer to next item
        delete temp; // delete former front 
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node; // create node
    // on failure, new throws std::bad_alloc exception
    add->item = item; // set node pointers
    add->next = NULL; // ofr nullptr
    items ++;
    if (front == NULL) // if queue is empty,
        front = add; // place item at front
    else
        rear->next = NULL; // else place at rear
    rear = add; // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue 把被删除的项目存起来
    items --;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}

// overloaded operators
bool Queue::operator<(const Queue & queue) const
{
    return (items < queue.items);
}

bool Queue::operator>(const Queue & queue) const
{
    return (items > queue.items);
}

bool Queue::operator==(const Queue & queue) const 
{
    return (items == queue.items);
}

// customer method

// when is the time at which the customer arrive
// the arrival time is set to when and the processing
// time set to a random value in range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}