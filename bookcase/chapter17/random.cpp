// random access to a binary file
// 随机存取二进制文件（移到指定位置进行读写）
// 随机存取常被用于数据库文件，维护一个独立的索引文件，指出数据在主数据文件中的位置
#include <iostream>
#include <fstream>
#include <iomanip> // io manipulator 读写控制器
#include <cstdlib> // for exit()

const int LIM = 20;

struct planet
{
    char name[LIM];
    double population;
    double g;
};

const char * file = "planets.dat"; 
inline void eatline() {while (std::cin.get() != '\n') continue;}

int main()
{
    using namespace std;
    planet pl;
    cout << fixed;

    // show initial contents
    // 继承自iostream类,iostream类基于istream、ostream类,所以继承了两个缓冲区，输入、输出
    // 输入输出指针一前一后移动，由tellg()、tellp()方法返回的值相同
    // 而如果是istream、ostrteam对象，输入、输出指针将彼此独立
    fstream finout; // read and write streams
    finout.open(file, 
            ios_base::in | ios_base::out | ios_base::binary);
    // NOTE: Some Unix systems require omitting | ios::binary
    int ct = 0;
    if (finout.is_open())
    {
        finout.seekg(0); // go to beginning(输入指针)
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (finout.read((char *) &pl, sizeof pl)) // 从二进制文件中循环读取pl结构
        {
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        if (finout.eof()) // 到文件末尾
            finout.clear(); // clear eof flag
        else 
        {
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cerr << file << " could not be opened --bye.\n";
        exit(EXIT_FAILURE);
    }

    // change a record
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline(); // get rid of newline
    if (rec < 0 | rec >= ct)
    {
        cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }
    // 将整型转换为streamops对象
    streampos place = rec * sizeof pl; // convert to streamops type
    finout.seekg(place); // random access 输入指针向前移动place
    if (finout.fail())
    {
        cerr << "Error on attemped seek\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char *) &pl, sizeof pl); // 从二进制文件中读取pl结构
    cout << "Your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
         << setprecision(0) << setw(12) << pl.population
         << setprecision(2) << setw(6) << pl.g << endl;
    if (finout.eof())
        finout.clear(); // clear eof flag

    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place); // go back 输出指针向后移动
    finout.write((char *) &pl, sizeof pl) << flush; // 向二进制文件中写入pl结构后清空缓冲区
    if (finout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

    // show revised file
    ct = 0;
    finout.seekg(0); // go to beginning of file
    cout << "Here are the new contents of the " << file
         << " file: \n";
    while (finout.read((char *) &pl, sizeof pl)) // 循环每次读取二进制文件中的pl结构
    {
        cout << ct ++ << ": " << setw(LIM) << pl.name << ": "
             << setprecision(0) << setw(12) << pl.population
             << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close(); // 将finout与文件的连接断开
    cout << "Done\n";

    return 0;
}
