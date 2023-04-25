// using serveral STL elements
// 使用STL组件
//

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

char toLower(char ch) {
  return tolower(ch);
}  // 因为 int tolower(int) ，所以需作为内部调用传ch自动类型转换为int，
string& ToLower(string& st);
void display(const string& s);

int main() {
  vector<string> words;
  cout << "Enter words (enter quit to quit):\n";
  string input;
  while (cin >> input && input != "quit")
    words.push_back(input);  // 矢量向末尾追加元素,自动增长矢量长度

  cout << "You entered the following words:\n";
  for_each(words.begin(), words.end(), display);
  cout << endl;

  // place word in set, converting to lowercase
  set<string> wordset;
  // insert_iterator<set<string> > (wordset, wordset.begin()) 创建一个set<string>的插入迭代器对象，将wordset作为目标容器，将新元素从wordset的begin开始插入
  transform(words.begin(), words.end(),
            insert_iterator<set<string> >(wordset, wordset.begin()), ToLower); // 将words矢量的元素复制转为小写并插入到set<string>中，自动排序去重
  cout << "\n Alphabetic list of words: \n";
  for_each(wordset.begin(), wordset.end(), display);
  cout << endl;

  // place word and frequency in map
  map<string, int> wordmap; // 声明一个string:int的键值对map
  set<string>::iterator si;
  for (si = wordset.begin(); si != wordset.end(); si++)
    wordmap[*si] = count(words.begin(), words.end(), *si); // 将wordset中的元素值作为key，这个值出现的次数作为value，map[key] = value;更新或插入map

  // display map contents
  cout << "\n Word frequency:\n";
  for (si = wordset.begin(); si != wordset.end(); si++)
    cout << *si << ": " << wordmap[*si] << endl; // map支持数组表示法取value作为左值: map[key]

  return 0;
}

// 从st的begin迭代器到end迭代器作为参数执行toLower，输出到st的begin迭代器开始的容器
string& ToLower(string& st) {
  transform(st.begin(), st.end(), st.begin(), toLower);
  return st;
}

void display(const string& s) { cout << s << " "; }