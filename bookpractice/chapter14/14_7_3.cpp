// 虚基类最好不要做类模板的类型参数，当类模板中数据类型是指针时才可以
#include "14_7_3.h"

using std::cin;
using std::cout;
using std::endl;

////////////////////Woker/////////////////////

// Worker methods
Worker::~Worker() {}

void Worker::Set()
{
  Get();
}

void Worker::Show() const
{
  Data();
}

// protected methods
void Worker::Data() const {
  cout << "Name: " << fullname << endl;
  cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
  cout << "Enter worker's name: ";
  getline(cin, fullname);
  cout << endl;
  cout << "Enter worker's ID: ";
  cin >> id;
  while (cin.get() != '\n') continue;
}

// Waiter methods
void Waiter::Set() {
  Worker::Get();
  Get();
}

void Waiter::Show() const {
  cout << "Category: waiter\n";
  Worker::Data();
  Data();
}

// protected methods
void Waiter::Data() const { cout << "Panache rating: " << panache << endl; }

void Waiter::Get() {
  cout << "Enter waiter's panache rating: ";
  cin >> panache;
  while (cin.get() != '\n') continue;
}

// Singer methods

char* Singer::pv[Singer::Vtypes] = {"other", "alto",     "contralto", "soprano",
                                    "base",  "baritone", "tenor"};

void Singer::Set() {
  Worker::Get();
  Get();
}

void Singer::Show() const {
  cout << "Category: singer\n";
  Worker::Data();
  Data();
}

// protected methods
void Singer::Data() const { cout << "Vocal range: " << pv[voice] << endl; }

void Singer::Get() {
  cout << "Enter number for singer's vocal range: \n";
  int i;
  for (i = 0; i < Vtypes; i++) {
    cout << i << ": " << pv[i] << " ";
    if (i % 4 == 3) cout << endl;
  }
  if (i % 4 != 0) cout << "\n";
  cin >> voice;
  while (cin.get() != '\n') continue;
}

// // SingingWaiter methods
// void SingingWaiter::Data() const  // 派生类的辅助方法
// {
//   Singer::Data();
//   Waiter::Data();
// }

// void SingingWaiter::Get() {
//   Waiter::Get();
//   Singer::Get();
// }

// void SingingWaiter::Set() {
//   Worker::Get();
//   Get();
// }

// void SingingWaiter::Show() const {
//   cout << "Category: singing waiter\n";
//   Worker::Data();
//   Data();
// }

////////////////////Queue/////////////////////
// Queue methods
template <typename Type>
Queue<Type>::Queue(int qs) : qsize(qs) {
  front = rear = NULL;  // or nullptr
  items = 0;
}

template <typename Type>
Queue<Type>::~Queue() {
  Node* temp;
  // 一直删到front为NULL
  while (front !=
         NULL)  // 将front指针赋值给temp，front重置为next，释放掉temp指向的内存
  {
    temp = front;         // save address of front item
    front = front->next;  // reset pointer to next item
    delete temp;          // delete former front
  }
}

template <typename Type>
bool Queue<Type>::isempty() const {
  return items == 0;
}

template <typename Type>
bool Queue<Type>::isfull() const {
  return items == qsize;
}

template <typename Type>
int Queue<Type>::queuecount() const {
  return items;
}

// Add item to queue
template <typename Type>
bool Queue<Type>::enqueue(const Type& item) {
  if (isfull()) return false;
  Node* add = new Node;  // create node
  // on failure, new throws std::bad_alloc exception
  add->item = item;  // set node pointers
  add->next = NULL;  // ofr nullptr
  items++;
  if (front == NULL)  // if queue is empty,
    front = add;      // place item at front
  else
    rear->next = add;  // else place at rear
  rear = add;           // have rear point to new node
  return true;
}

// Place front item into item variable and remove from queue
template <typename Type>
bool Queue<Type>::dequeue(Type& item) {
  if (front == NULL) return false;
  item = front->item;  // set item to first item in queue 把被删除的项目存起来
  items--;
  Node* temp = front;   // save location of first item
  front = front->next;  // reset front to next item
  delete temp;          // delete former first item
  if (items == 0) rear = NULL;
  return true;
}

template<typename Type>
void Queue<Type>::show() const
{
    Node * temp = front;
    for (int i = 0; i < qsize; i ++, temp = temp->next)
      temp->item.Show();
}

template class Queue<Worker>;

// #include "14_7_3.h"

// template<class Type>
// Queue<Type>::Queue(int qs) :qsize(qs)
// {
// 	front = rear = nullptr;
// 	items = 0;
// }
// template<class Type>
// Queue<Type>::~Queue()
// {
// 	Node* temp;
// 	while (front != nullptr)
// 	{
// 		temp = front;
// 		front = front->next;
// 		delete temp;
// 	}
// }
// template<class Type>
// bool Queue<Type>::isempty()const
// {
// 	return items == 0;
// }
// template<class Type>
// bool Queue<Type>::isfull()const
// {
// 	return items == qsize;
// }
// template<class Type>
// int Queue<Type>::queuecount()const
// {
// 	return items;
// }
// template<class Type>
// bool Queue<Type>::enqueue(const Type& item)
// {
// 	if (isfull()) return false;
// 	Node* add = new Node;
// 	add->item = item;
// 	add->next = nullptr;
// 	items++;
// 	if (front == nullptr)
// 		front = add;
// 	else
// 		rear->next = add;
// 	rear = add;
// 	return true;
// }
// template<class Type>
// bool Queue<Type>::dequeue(Type& item)
// {
// 	if (front == nullptr) return false;
// 	item = front->item;
// 	items--;
// 	Node* temp = front;
// 	front = front->next;
// 	delete temp;
// 	if (items == 0)
// 		rear = nullptr;
// 	return true;
// }
// template<class Type>
// void Queue<Type>::show()const
// {
// 	Node* temp = front;
// 	for (int in = 0; in < qsize; in++, temp = temp->next)
// 		temp->item.show();
// }


// Worker& Worker::operator = (const Worker& wok)
// {
// 	this->fullname = wok.fullname;
// 	this->id = wok.id;
// 	return *this;
// }
// void Worker::show()const
// {
// 	std::cout << this->fullname << ",  " << this->id << std::endl;
// }

// template class Queue<Worker>;