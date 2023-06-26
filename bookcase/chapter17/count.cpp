// counting characters in a list of files
// 计算命令行列出的文件包含的字符数
// count.out file1 file2 
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[]) // 第一个参数为命令名，argc为命令行参数个数，argv为指针数组
{
    using namespace std;

    if (argc == 1) // quit if no arguments
    {
        cerr << "Usage: " << argv[0] << " filenames[s]\n"; // 表示错误消息
        exit(EXIT_FAILURE);
    }

    ifstream fin; // open stream
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++)
    {
        fin.open(argv[file]); // connect stream to argv[file]
        if (!fin.is_open())
        {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while (fin.get(ch)) // 从文件中读取字符到程序中
            count++;
        cout << count << " characters in " << argv[file] << endl;
        total += count;
        fin.clear(); // needed for some implementations
        fin.close(); // disconnect file
    }
    cout << total << " characters in all files\n";
    return 0;
}