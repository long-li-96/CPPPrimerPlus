// using a functor
// 使用重载了()运算符的类对象

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

template <class T>  // functor class defines operator()()
class TooBig {
 private:
  T cutoff;

 public:
  TooBig(const T& t) : cutoff(t) {}
  bool operator()(const T& v) { return v > cutoff; } // 重载()操作符，使类成为谓词（返回bool的一元函数）
};

void outint(int n) { std::cout << n << " "; }

int main() {
  using std::cout;
  using std::endl;
  using std::list;

  TooBig<int> f100(100);  // limit = 100
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
  yadayada.remove_if(f100);              // use a named function object list模板中的类成员接受一个谓词
  etcerera.remove_if(TooBig<int>(200));  // construct a function object 

  cout << "Trimmed lists: \n";
  for_each(yadayada.begin(), yadayada.end(), outint);

  cout << endl;
  for_each(etcerera.begin(), etcerera.end(), outint);
  cout << endl;
  return 0;
}

// 二元函数符可以转化为一元函数符（重载了()的类）