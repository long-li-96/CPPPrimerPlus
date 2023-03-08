// multiple inheritance
#include <cstring>
#include <iostream>

#include "workermi.h"

const int SIZE = 5;

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Worker* lolas[SIZE];

  int ct;
  for (ct = 0; ct < SIZE; ct++) {
    char choice;
    cout << "Enter the employee category: \n"
         << "w: waiter s: singer "
         << "t: singing waiter q: quit\n";
    cin >> choice;
    // 第一个参数str是要被查找的字符串，第二个参数character是要查找的字符。如果查找成功，函数将返回一个指向该字符第一次出现位置的指针；如果查找失败，函数将返回nullptr。
    while (strchr("wstq", choice) == NULL) {
      cout << "Please enter a w, s, t, or q: ";
      cin >> choice;
    }
    if (choice == 'q') break;
    switch (choice) {
      case 'w':
        lolas[ct] = new Waiter;
        break;
      case 's':
        lolas[ct] = new Singer;
        break;
      case 't':
        lolas[ct] = new SingingWaiter;
        break;
    }
    cin.get();
    lolas[ct]->Set();
  }
  cout << "\nHere is your staff:\n";
  int i;
  for (i = 0; i < ct; i++) {
    cout << endl;
    lolas[i]->Show();
  }
  for (i = 0; i < ct; i++) delete lolas[i];
  cout << "Bye.\n";
  return 0;
}