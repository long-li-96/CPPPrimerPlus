#include <cstring>

#include "14_7_3.h"

const int SIZE = 5;

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Queue<Worker> queue_worker(SIZE);
  Worker* worker_temp[SIZE];

  int ct;
  for (ct = 0; ct < SIZE; ct++) {
    char choice;
    cout << "Enter the employee category: \n"
         << "w: waiter s: singer t: SingingWaiter "
         << "q: quit\n";
    cin >> choice;
    // 第一个参数str是要被查找的字符串，第二个参数character是要查找的字符。如果查找成功，函数将返回一个指向该字符第一次出现位置的指针；如果查找失败，函数将返回nullptr。
    while (strchr("wstq", choice) == NULL) {
      cout << "Please enter a w, s, t, or q: ";
      cin >> choice;
    }
    while (cin.get() != '\n') continue;
    if (choice == 'q') break;
    switch (choice) {
      case 'w':
        worker_temp[ct] = new Waiter;
        worker_temp[ct]->Set();
        queue_worker.enqueue(worker_temp[ct]);
        break;
      case 's':
        worker_temp[ct] = new Singer;
        worker_temp[ct]->Set();
        queue_worker.enqueue(worker_temp[ct]);
        break;
      case 't':
        worker_temp[ct] = new SingingWaiter;
        worker_temp[ct]->Set();
        queue_worker.enqueue(worker_temp[ct]);
        break;
    }
    cout << endl;
  }
  cout << "\nHere is your staff:\n";
  int i;
  queue_worker.show();
  cout << queue_worker.queuecount() << endl;
  cout << "Bye.\n";
  return 0;
}