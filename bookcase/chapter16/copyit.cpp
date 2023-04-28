// copy() and iterators
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  using namespace std;

  int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
  vector<int> dice(10);
  // copy from array to vector
  copy(casts, casts + 10, dice.begin());
  cout << "Let the dice be cast!\n";

  // createan ostream iterator
  
  ostream_iterator<int, char> out_iter(cout,
                                       " ");  // 输出迭代器,将int输出为char
  // istream_iterator<int, char>(cin) // 将int读取为char并由cin管理的输入流匿名对象 
  /*
  copy(istream_iterantor<int, char>(cin), istream_iterator<int, char>(), dice.begin()); 

  istream_iterator<int, char>()省略构造函数参数表示输入失败
  */

  // copy from vector to output // 适配器
  copy(dice.begin(), dice.end(),
       out_iter);  // 将dice[begin(),end())从out_iter开始复制
  // 因为out_iter是输出迭代器,所以复制时一并进行输出
  cout << endl;

  cout << "Implicit use of reverse iterator.\n";
  // 
  copy(dice.rbegin(), dice.rend(), out_iter); // out_iter可以被替代为匿名迭代器ostream_iterator<int, char> out_iter(cout, " ")，隐式使用，尽量采取这种

  cout << endl;

  cout << "Explicit use of reverse iterator.\n";
  vector<int>::reverse_iterator ri;  // 定义反向迭代器，先递减再解除引用, ri为位置6时，*ri取的值为位置5的

  for (ri = dice.rbegin(); ri != dice.rend(); ++ri) cout << *ri << " "; // 显式使用
  cout << endl;

  return 0;
}