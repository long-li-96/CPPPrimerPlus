// 将键盘输入(直到模拟的文件尾)复制到通过命令行指定的文件(可能有多个)中
#include <iostream>
#include <fstream>
#include <cstdlib>
inline void eatline() {while (std::cin.get() != '\n') continue;}

int main(int argc, char * argv[])
{
    using namespace std;

    if (argc == 1)
    {
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout;
    char ch;
    for (int file = 1; file < argc; file++)
    {
        fout.open(argv[file], ios::out | ios::app);
        if (!fout.is_open())
        {
            cerr << "could not open " << argv[file] << endl;
            fout.clear();
            continue;
        }
        cout << "Please enter the words you want to input to the file(enter '#' to stop):\n";
        while (cin.get(ch)) // 输入'#'模拟达到文件末尾
        {
            if (ch != '#')
                fout << ch;
            else 
            {
                // cin.putback(ch); // 这个‘#’被重新放入输入流中的话,下个文件的输入直接就到了break
                break;
            }
        }
        eatline();
        cin.clear();
        fout.close();
    }
    cout << "Done.\n";
    return 0;
}
