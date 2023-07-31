/*
使用lambda重新编写程序functor.cpp，具体地说，使用一个有名称的lambda替换函数outint(),
并将函数符替换为两个匿名lambda表达式.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
auto outint = [](int n) { std::cout << n << " "; };

int main() {
  using std::cout;
  using std::endl;
  using std::list;
  int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
  list<int> yadayada(vals, vals + 10);  // range constructor
  list<int> etcerera(vals, vals + 10);
  // C++11 can use the following instead
  // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}
  // list <int> etcerera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201}
  cout << "Original lists: \n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  cout << endl;
  for_each(etcerera.begin(), etcerera.end(), outint);
  cout << endl;
  yadayada.remove_if([](int n){return n > 100;});
  etcerera.remove_if([](int n){return n > 200;});
  cout << "Trimmed lists: \n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  cout << endl;
  for_each(etcerera.begin(), etcerera.end(), outint);
  return 0;
}
