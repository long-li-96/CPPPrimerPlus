// #include <iostream>
// #include <string>
// using namespace std;

// template <typename T>
// class Queue
// {
// private:
//     struct Node
//     {
//         T data;
//         Node* next;
//         Node(const T& d) : data(d), next(nullptr) {}
//     };
//     Node* head;
//     Node* tail;
// public:
//     Queue() : head(nullptr), tail(nullptr) {}
//     void push(const T& d)
//     {
//         Node* new_node = new Node(d);
//         if (tail == nullptr)
//         {
//             head = new_node;
//             tail = new_node;
//         }
//         else
//         {
//             tail->next = new_node;
//             tail = new_node;
//         }
//     }
//     T pop()
//     {
//         if (head == nullptr)
//             throw runtime_error("queue is empty");
//         T data = head->data;
//         Node* temp = head;
//         head = head->next;
//         if (head == nullptr)
//             tail = nullptr;
//         delete temp;
//         return data;
//     }
// };

// class Worker
// {
// private:
//     string name;
//     int age;
// public:
//     Worker(const string& n, int a) : name(n), age(a) {}
//     void print() const
//     {
//         cout << "Name: " << name << ", Age: " << age << endl;
//     }
// };

// int main()
// {
//     Queue<Worker> q;
//     q.push(Worker("Alice", 30));
//     q.push(Worker("Bob", 25));
//     q.push(Worker("Charlie", 35));
//     cout << "Workers in queue:" << endl;
//     while (true)
//     {
//         try
//         {
//             Worker w = q.pop();
//             w.print();
//         }
//         catch (const runtime_error& e)
//         {
//             cout << e.what() << endl;
//             break;
//         }
//     }
//     return 0;
// }


#include<iostream>
#include<string>
class Worker
{
private:
	std::string fullname;
	long id;
public:
	Worker() :fullname("None"), id(0L){}
	Worker(const std::string& fn, long n) :fullname(fn), id(n){}
	~Worker(){}
	void set(const std::string& fn, long n){ fullname = fn; id = n; }
	Worker& operator=(const Worker& wok);
	void show()const;
};

template<typename Type>
class Queue
{
private:
	struct Node { Type item; Node* next; };
	enum { Q_SIZE = 10 };
	Node* front, *rear;
	int items;
	const int qsize;
	Queue(const Queue& q) :qsize(0){}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Type& item);
	bool dequeue(Type& item);
	void show()const;
};

template<typename Type>
Queue<Type>::Queue(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}
template<typename Type>
Queue<Type>::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<typename Type>
bool Queue<Type>::isempty()const
{
	return items == 0;
}
template<typename Type>
bool Queue<Type>::isfull()const
{
	return items == qsize;
}
template<typename Type>
int Queue<Type>::queuecount()const
{
	return items;
}
template<typename Type>
bool Queue<Type>::enqueue(const Type& item)
{
	if (isfull()) return false;
	Node* add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
template<typename Type>
bool Queue<Type>::dequeue(Type& item)
{
	if (front == nullptr) return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}
template<typename Type>
void Queue<Type>::show()const
{
	Node* temp = front;
	for (int in = 0; in < qsize; in++, temp = temp->next)
		temp->item.show();
}


Worker& Worker::operator = (const Worker& wok)
{
	this->fullname = wok.fullname;
	this->id = wok.id;
	return *this;
}
void Worker::show()const
{
	std::cout << this->fullname << ",  " << this->id << std::endl;
}

const int SIZE = 3;
int main()
{
	int count = 0;
	Worker* pWorker = new Worker[SIZE];
	pWorker[0] = Worker("Jim", 1001);
	pWorker[1] = Worker("Tom", 1002);
	pWorker[2] = Worker("Tim", 1003);
	Queue<Worker> queue(3);
	while (queue.queuecount() < 3)
		queue.enqueue(pWorker[count++]);
	if (queue.queuecount() == 3)std::cout << "The Queue is full, the elements are: \n";
	queue.show();
	while (queue.queuecount() > 0)
		queue.dequeue(pWorker[--count]);
	if (queue.queuecount() == 0)std::cout << "The Queue is empty now. \n";
	delete[] pWorker;
	system("pause");
	return 0;
}