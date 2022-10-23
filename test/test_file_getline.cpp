#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
int main()
{
    using namespace std;
    string filename;
    char name[50];
    cout << "Enter name of the file: " << endl;
    getline(cin,filename);
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    int num;
    inFile >> num;
    inFile.get(); //读取换行符
     while(inFile.good())
    {
        for (int i = 0;i<num; i++)
        {
        inFile.getline(name,50,'\n'); //读取一行字符 ，字符串与数字混合读取时，字符串会被空格代替
        cout << name << endl;
        }
    }
    if (inFile.eof())
        cout << endl <<"End of file reached.\n";
    inFile.close();
}