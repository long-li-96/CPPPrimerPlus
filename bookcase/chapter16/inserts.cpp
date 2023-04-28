// copy() and insert iterators
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
// 三种插入迭代器：back_insert_iterator、front_insert_iterator、insert_iterator的适用需求：预先不知道容器的长度、新增容器元素
void output(const std::string& s) { std::cout << s << " "; }

int main() {
  using namespace std;
  string s1[4] = {"fine", "fish", "fashion", "fate"};
  string s2[2] = {"busy", "bats"};
  string s3[2] = {"silly", "singers"};
  vector<string> words(4);
  copy(s1, s1 + 4, words.begin());

  for_each(words.begin(), words.end(), output);
  cout << endl;

  // construct anonymous back_insert_iterator object
  copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words)); // back_insert_iterator<vector<string> > (words) // 只能用于允许在尾部快速插入的容器：vector：动态数组、
  // deque：双端队列、list：双向链表、forward_list：单向链表，声明容器类型为了使用合适的容器方法，这个类型有push_back()方法
  for_each(words.begin(), words.end(), output);
  cout << endl;

  // constructor anonymous insert_iterator object
  copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin())); // insert_iterator<vector<string> > (words, words.begin()) // 只能用于允许在任意位置快速插入的容器：vector：动态数组、
  // deque：双端队列、list：双向链表、forward_list：单向链表、set及multiset：基于红黑树实现的有序集合、map及multimap：基于红黑树实现的有序关联数组，声明容器类型为了使用合适的容器方法，words.begin用于指示插入位置,这个类型有insert()方法
  for_each(words.begin(), words.end(), output);

  cout << endl;
  return 0;
}