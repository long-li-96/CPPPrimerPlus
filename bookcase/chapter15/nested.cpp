// using a queue that has a nested class
#include <iostream>
#include <string>

#include "queuetp.h"

int main() {
  using std::cin;
  using std::cout;
  using std::string;

  QueueTp<string> cs(5);

  string temp;

  while (!cs.isfull()) {
    cout << "Please enter your nam, you will be served in the order"
            " of arrival.\n"
            "name: ";
    getline(cin, temp);
    cs.enqueue(temp);
  }

  cout << "THe queue is full, Processing begins!\n";
  while (!cs.isempty()) {
    cs.dequeue(temp);
    cout << "Now processing " << temp << "...\n";
  }
  return 0;
}