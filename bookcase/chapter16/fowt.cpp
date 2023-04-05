// 使用shared_ptr,当最后一个指针过期时，才调用delete，适用于多个指针指向同一个对象时，delete的问题

#include <iostream>
#include <memory>
#include <string>

int main() {
  using namespace std;
  shared_ptr<string> films[5] = {
      shared_ptr<string>(new string("Fowl Balls")),
      shared_ptr<string>(new string("Duck Walks")),
      shared_ptr<string>(new string("Chicken Runs")),
      shared_ptr<string>(new string("Turkey Errors")),
      shared_ptr<string>(new string("Goose Eggs"))};

  shared_ptr<string> pwin;
  pwin = films[2];  // films[2] loses ownership

  cout << "The nominess for best avian baseball film are\n";
  for (int i = 0; i < 5; i++) {
    cout << *films[i] << endl;
  }
  cout << "The winner is " << *pwin << "!\n";
  cin.get();
  return 0;
}