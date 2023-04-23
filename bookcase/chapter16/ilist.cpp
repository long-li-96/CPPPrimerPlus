// use initializer_list (c++11 feature)
// initializer_list 包含 begin()、end() size()，可使函数接受不定长的初始化列表{}

#include <initializer_list>
#include <iostream>

// 类处理长度不同的列表，提供接受initializer_list作为参数

double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> &ril);

int main() {
  using std::cout;

  cout << "List 1: sum = " << sum({2, 3, 4}) << ", ave = " << average({2, 3, 4})
       << "\n";

  std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
  cout << "List 2: sum = " << sum(dl) << ", ave = " << average(dl) << "\n";

  dl = {16.0, 25.0, 36.0, 40.0, 64.0}; // initializer_list对象可以更改赋值
  cout << "List 3: sum = " << sum(dl)
       << ", ave = " << average(dl) << '\n';

  return 0;
}

double sum(std::initializer_list<double> il) {
  double tot = 0;
  for (auto p = il.begin(); p != il.end(); p++) tot += *p;
  return tot;
}

double average(const std::initializer_list<double> &ril) {
  double tot = 0;
  int n = ril.size();
  double ave = 0.0;
  if (n > 0) {
    for (auto p = ril.begin(); p != ril.end(); p++) tot += *p;
    ave = tot / n;
  }
  return ave;
}
