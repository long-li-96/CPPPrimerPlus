// binary file I/O
// 二进制文件读写
#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip> // io manipulator
#include <cstdlib> // for exit()

inline void eatline() {while (std::cin.get() != '\n') continue;}

struct planet
{
    char name[20];
    double population; // its population
    double g; // its accleration of gravity

};

const char * file = "planet.dat";

int main()
{
    using namespace std;
    planet pl;
    cout << fixed << right; // 使用fixed控制符,显示末尾的0，right右对齐

    

    // show initial contents
    ifstream fin; // 创建输入流对象
    fin.open(file, ios_base::in | ios_base::binary); // binary file 将输入流对象以二进制读模式连接到文件，这个文件是二进制文件
    // NOTE: some systems don't accept the ios_base::binary mode
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (fin.read((char *) &pl, sizeof pl)) // 从文件中赋值pl个字符到pl结构中
        {
            cout << setw(20) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    // add new data
    ofstream fout(file, 
    ios_base::out | ios_base::app | ios_base::binary); // 如果文件不存在则创建文件并以二进制追加写的模式打开这个文件
    // NOTE: some systems don't accept the ios_base::binary mode
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0') // pl.name非空字符串?
    {
        eatline();
        cout << "Enter planetary population: ";
        cin >> pl.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> pl.g;
        eatline();
        // 将&pl转化为字符指针，write要求第一个参数为字符指针，第二个参数为要写入的字节数
        fout.write((char *) &pl, sizeof pl); // 将pl作为一个整体存入文件中,将
        cout << "Enter planet name (enter a blank line to quit): \n";
        cin.get(pl.name, 20); // 碰到换行符终止循环
    }
    fout.close(); // 关闭fout与文件的连接

    // show revised file
    fin.clear(); // not required for some implementations, but won't hurt
    fin.open(file, ios_base::in | ios_base::binary); // 以二进制读模式连接到文件，这个文件是二进制文件
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
             << file << " file:\n";
        while (fin.read((char *) & pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "Done.\n";
    return 0;
}