#ifndef WORKER_QUEUE_H
#define WORKER_QUEUE_H

#include <iostream>
#include <string>

class Worker  // an base class
{
 private:
  std::string fullname;
  long id;

 protected:
  virtual void Data() const;
  virtual void Get();

 public:
  Worker() : fullname("no one"), id(0L) {}
  Worker(const std::string &s, long n) : fullname(s), id(n) {}
  virtual ~Worker();  
  virtual void Set();
  virtual void Show() const;
};

class Waiter : public Worker  // 继承自基类
{
 private:
  int panache;

 protected:
  void Data() const;
  void Get();

 public:
  Waiter() : Worker(), panache(0) {}
  Waiter(const std::string &s, long n, int p = 0) : Worker(s, n), panache(p) {}
  Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
  void Set();
  void Show() const;
};

class Singer : public Worker {
 protected:
  enum { other, alto, contralto, soprano, base, baritone, tenor };
  enum { Vtypes = 7 };
  void Data() const;
  void Get();

 private:
  static char *pv[Vtypes];  // string equivs of voice types
  int voice;

 public:
  Singer() : Worker(), voice(other) {}
  Singer(const std::string &s, long n, int v = other)
      : Worker(s, n), voice(v) {}
  Singer(const Worker &wk, int v = other) : Worker(wk), voice(v) {}
  void Set();
  void Show() const;
};

// multiple inheritance
// class SingingWaiter : public Singer, public Waiter {
//  protected:
//   void Data() const;
//   void Get();

//  public:
//   SingingWaiter() {}
//   // 构造虚基类对象，避免构造基类对象（同一虚基类派生来）传递冲突
//   SingingWaiter(const std::string &s, long n, int p = 0, int v = other)
//       : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
//   SingingWaiter(const Worker &wk, int p = 0, int v = other)
//       : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
//   SingingWaiter(const Waiter &wt, int v = other)
//       : Worker(wt), Waiter(wt), Singer(wt, v) {}
//   SingingWaiter(const Singer &sg, int p = 0)
//       : Worker(sg), Waiter(sg), Singer(sg) {}
//   void Set();
//   void Show() const;
// };

template <typename Type>
class Queue {
 private:
  struct Node {
    Type item;
    struct Node *next;
  };
  enum { Q_SIZE = 10 };
  Node *front;      // pointer to front of Queue
  Node *rear;       // pointer to rear of Queue
  int items;        // current number of items in Queue
  const int qsize;  // maximum number of items in Queue
  // preemptive definitions to prevent public copying
  Queue(const Queue &q) : qsize(0) {}                 // copy constructor
  Queue &operator=(const Queue &q) { return *this; }  // assignment operator
 public:
  Queue(int qs = Q_SIZE);
  ~Queue();
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Type &item);  // add item to end of queue
  bool dequeue(Type &item);        // remove item from front of queue
  void show() const;
};
#endif


// #ifndef QUEUE_H_
// #define QUEUE_H_
// #include<iostream>
// #include<string>
// class Worker
// {
// private:
// 	std::string fullname;
// 	long id;
// public:
// 	Worker() :fullname("None"), id(0L){}
// 	Worker(const std::string& fn, long n) :fullname(fn), id(n){}
// 	~Worker(){}
// 	void set(const std::string& fn, long n){ fullname = fn; id = n; }
// 	Worker& operator=(const Worker& wok);
// 	void show()const;
// };

// template<class Type>
// class Queue
// {
// private:
// 	struct Node { Type item; Node* next; };
// 	enum { Q_SIZE = 10 };
// 	Node* front, *rear;
// 	int items;
// 	const int qsize;
// 	Queue(const Queue& q) :qsize(0){}
// 	Queue& operator=(const Queue& q) { return *this; }
// public:
// 	Queue(int qs = Q_SIZE);
// 	~Queue();
// 	bool isempty()const;
// 	bool isfull()const;
// 	int queuecount()const;
// 	bool enqueue(const Type& item);
// 	bool dequeue(Type& item);
// 	void show()const;
// };

// #endif