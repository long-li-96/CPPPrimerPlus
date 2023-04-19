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
    words.push_back(input);  // 矢量向末尾追加元素

  cout << "You entered the following words:\n";
  for_each(words.begin(), words.end(), display);
  cout << endl;

  // place word in set, converting to lowercase
  set<string> wordset;
  transform(words.begin(), words.end(),
            insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
  cout << "\n Alphabetic list of words: \n";
  for_each(wordset.begin(), wordset.end(), display);
  cout << endl;

  // place word and frequency in map
  map<string, int> wordmap;
  set<string>::iterator si;
  for (si = wordset.begin(); si != wordset.end(); si++)
    wordmap[*si] = count(words.begin(), words.end(), *si);

  // display map contents
  cout << "\n Word frequency:\n";
  for (si = wordset.begin(); si != wordset.end(); si++)
    cout << *si << ": " << wordmap[*si] << endl;

  return 0;
}

string& ToLower(string& st) {
  transform(st.begin(), st.end(), st.begin(), toLower);
  return st;
}

void display(const string& s) { cout << s << " "; }