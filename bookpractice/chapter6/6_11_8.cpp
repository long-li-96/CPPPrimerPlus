#include <iostream>
#include <fstream>
#include <cstdlib> // support for exit()
#include <string>
int main()
{
    using namespace std;
    string filename;
    cout << "Enter name of the file: " << endl;
    getline(cin,filename);
    int count = 0;
    char value;
    ifstream inFile; // 读取文件的对象
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    inFile >> value;
    while(inFile.good()) // 读取正常？
    {
        ++count;
        cout << value;
        inFile >> value;
    }
    if (inFile.eof()) // 判断文件结尾
        cout << endl <<"End of file reached.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else 
    {
        cout << "Items read: " << count << endl;
    }
    inFile.close();
    return 0;
}