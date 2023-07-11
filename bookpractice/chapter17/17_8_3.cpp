// 将一个文件复制到另一个文件中，让程序通过命令行获取文件名。如果文件无法打开，程序将指出这一点
#include <iostream>
#include <fstream>
#include <cstdlib>
inline void eatline() {while (std::cin.get() != '\n') continue;}

int main(int argc, char * argv[])
{
    using namespace std;

    if (argc != 3)
    {
        cerr << "The Number of paramters is not correct!\n";
        exit(EXIT_FAILURE);
    }
    char * file1 = argv[1]; // 读取的文件
    char * file2 = argv[2]; // 写入的文件
    char ch; // 中间变量
    ofstream fout(file2,ios::out | ios::app); // 追加写入
    if (!fout.is_open())
    {
        cerr << "Can't open " << file2 << " file for output.\n";
        exit(EXIT_FAILURE); // 打开文件失败，退出程序
    }
    ifstream fin(file1);
    if (!fin.is_open())
    {
        cerr << "Can't open " << file1 << " file for input.\n";
        exit(EXIT_FAILURE); // 打开文件失败，退出程序
    }
    while (fin.get(ch)) // 从文件中读取字符到程序中
        fout << ch;     // 从程序中写入道文件中
    fin.clear();
    fin.close();
    fout.close();
    return 0;
}