// read strings from a file
// getline指定分界符：来读取

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  using namespace std;

  ifstream fin;  // 文件读取输入对象：将文件这种外部数据输入到程序中的变量
  fin.open(
      "/Users/kali/Desktop/projects/c:c++/CaddaddPrimerPlus/testfile/"
      "tobuy.txt");
  if (!fin.is_open()) {
    cerr << "Can't open file. Bye.\n";
    exit(EXIT_FAILURE);
  }
  string item;
  int count = 0;
  getline(fin, item, ':');
  while (fin)  // while input is good
  {
    ++count;
    cout << count << ": " << item << endl;
    getline(fin, item, ':');
  }
  cout << "Done\n";
  fin.close();  // 文件读取输入对象关闭文件
  return 0;
}
