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

const char * file = "planets.dat";

int main()
{
    using namespace std;
    planet pl;
    cout << fixed << right; // 使用fixed控制符,显示末尾的0，right右对齐

    // show initial contents
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary); // binary file
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
    ios_base::out | ios_base::app | ios_base::binary);
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
        fout.write((char *) &pl, sizeof pl); // 将pl个字符复制到文件中（二进制）
        cout << "Enter planet name (enter a blank line to quit): \n";
        cin.get(pl.name, 20); // 碰到换行符终止循环
    }
    fout.close();

    // show revised file
    fin.clear(); // not required for some implementations, but won't hurt
    fin.open(file, ios_base::in | ios_base::binary);
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