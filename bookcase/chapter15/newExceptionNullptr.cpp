// new异常返回空指针
#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big {
  double stuff[2000];
  Big() {}
};

int main(void) {
  Big* pb;
  pb = new (std::nothrow) Big[10000];  // 分配内存失败则返回空指针

  if (pb == 0) {
    cout << "Could not allocate memory. Bye. \n";
    exit(EXIT_FAILURE);
  }

  cout << "Memory successfully allocated\n";
  pb[0].stuff[0] = 4;
  cout << pb[0].stuff[0] << endl;
  delete[] pb;
  return 0;
}