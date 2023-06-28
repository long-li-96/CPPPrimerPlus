// appending information to a file
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit()

const char * file = "guests.txt";

int main()
{
    using namespace std;
    char ch;

    // show initial contents
    ifstream fin;
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the"
             << file << " file:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
    }

    // add new names
    ofstream fout(file, ios::out | ios::app); // 对应C语言的"a" 追加
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE); // 打开文件失败，退出程序
    }
    cout << "Enter guest names (enter a blank line to quit):\n";
    string name;
    while (getline(cin, name) && name.size() > 0)
        fout << name << endl;
    fout.close();

    // show revised file
    fin.clear(); // not necessary for some compilers
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
             << file << " file:\n";
        while (fin.get(ch)) // 从文件中读取单个字符给到程序中ch变量
            cout << ch;
        fin.close();
    }

    cout << "Done.\n";
    return 0;
}
