// formatted reading from a char array
// 使用重载的>>读取istringstream对象中字符串的内容
// istringstream、ostringstream使得能够使用istream、ostream的方法来管理存储在字符串的字符数据

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;
    string lit = "It was a disk and stormy day, and "
                 " the full moon glowed brilliantly. "; // c++自动拼接这两行字符串为一个字符串
    istringstream instr(lit); // use buf for input 使用lit进行初始化，将lit字符串放入缓冲区中，这样可以使用istream方法来对这个字符串进行管理
    string word;
    while (instr >> word) // read a word a time // 使用>>从istringstream对象中读取字符串 // 从缓存区中输入到程序中的word
                          // 因为等于cin >> string ，所以碰到空格就结束读取，所以每次读一个
        cout << word << endl;
    return 0;
}

// c++中通过将被缓冲流同程序及输入源连接来处理输入，将被缓冲流同程序及输出目标连接来处理输出，iostream和fstream文件构成了I/O类库，包含iostream文件，自动打开8个流，使用8个对象来管理（cin、cout、cerr、clog、wcin...）
// istream类定义了多个版本的抽取运算符>>用来识别所有的c++基本类型，并将字符输入转换为这些类型
// 文本文件以字符形式存储所有的信息，二进制文件使用计算机的二进制表示来存储信息，对浮点值更为精确、简洁，可移植性较差
// sstream头文件中定义了istringstream类、ostringstream类，使得能够使用istream、ostream的方法来抽取字符串中的信息，对要放入字符串中的信息进行格式化：内核格式化