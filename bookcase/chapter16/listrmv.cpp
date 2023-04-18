// applying the STL to a string
// remove()STL算法不是由对象调用，接受区间参数，返回新的超尾值迭代器，将未被删除的元素房放在链表的开始位置
// remove()返回的迭代器需要有一个左值接收
// 可以再通过list.erase(iterator1,iterator2)来删除一个区间

#include <algorithm>
#include <iostream>
#include <list>

void Show(int);
const int LIM = 10;

int main() {
  using namespace std;
  int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
  list<int> la(ar, ar + LIM);
  list<int> lb(la);

  cout << "Original list contents: \n \t";
  for_each(la.begin(), la.end(), Show);
  cout << endl;

  la.remove(4);
  cout << "After using the remove() method:\n";
  cout << "la: \t";
  for_each(la.begin(), la.end(), Show);
  cout << endl;

  list<int>::iterator last;
  last = remove(lb.begin(), lb.end(), 4);
  cout << "After using the remove() function:\n";
  cout << "lb: \t";
  for_each(lb.begin(), lb.end(), Show);
  cout << endl;

  lb.erase(last, lb.end());
  cout << "After using the erase() method:\n";
  cout << "lb: \t";
  for_each(lb.begin(), lb.end(), Show);
  cout << endl;
  return 0;
}

void Show(int v) { std::cout << v << ' '; }