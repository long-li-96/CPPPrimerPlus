#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
struct contribution{
    string name;
    double payment;
};
int main()
{
    int num;
    string filename;
    double payment;
    cout << "Enter name of the file: " << endl;
    // 打开文件，读取文件
    getline(cin, filename); // 输入文件名
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    inFile >> num;
    inFile.get(); //读取换行符
    contribution * contributions = new contribution [num]; //动态分配结构数组的指针
    for (int i = 0;i<num; i++)
    {
        // infile, 等价于cin对象，string用getline(cin, string)
        getline(inFile,(contributions+i)->name); //读取一行字符,不要用infile.getline()来混合读取数字、字符串
        inFile >> (contributions+i)->payment;
        inFile.get();
    }
    if (inFile.eof())
        cout << endl <<"End of file reached.\n";
    inFile.close();
    // 输出
    int sum_g=0,sum_l=0;
    cout << "Grand patrons: " << endl;
    for (int i = 0;i<num;i++)
    {
        if ((contributions+i)->payment > 10000)
        {
            sum_g++;
            cout << (contributions+i)->name << endl;
            cout << (contributions+i)->payment << endl;
        }
    }
    if (sum_g == 0)
            cout << "None";
    cout << "patrons: " << endl;
    for (int i = 0;i<num;i++)
    {
        if ((contributions+i)->payment <= 10000)
        {
            sum_l++;
            cout << (contributions+i)->name << endl;
            cout << (contributions+i)->payment << endl;
        }
    }
    if (sum_l == 0)
            cout << "None";
    delete [] contributions;
    return 0;
}
