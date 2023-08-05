/*
下面是某个程序的部份代码，该程序将键盘输入读取到一个由string对象组成的vector中，将字符串内容（
而不是string对象）存储到一个文件中，然后该文件的内容复制到另一个由string对象组成的vector中。
该程序以二进制格式打开文件，并想使用read()和write()来完成I/O。余下的工作如下所述。
· 编写函数void ShowStr(const string &), 它显示一个string对象，并在显示完后换行。
· 编写函数Store，它将字符串信息写入到文件中。Store的构造函数应接受一个指定ofstream对象的参数，
而重载的operator()(const string &)应指出要写入到文件中的字符串。一种可行的计划是，首先将字符串的
长度写入到文件中，然后将字符串的内容写入到文件中。例如，如果len存储来字符串的长度，可以这样做：
os.write((char *) &len, sizeof(std::size_t)); // store length
os.write(s.data(), len); // store characters
成员函数data返回一个指针，该指针指向一个其中存储字符串中字符的数组，它类似于成员函数c_str()，只是后者在数组末尾加上了一个空字符。
· 编写函数GetStrs(), 它根据文件恢复信息。该函数可以使用read()来获得字符串的长度，然后使用一个循环从文件中读取相应数量的字符，并
将它们附加到一个原来为空的临时string末尾。由于string的数据是私有的，因此必须使用string类的方法来将数据存储到string对象中，
而不能直接存储。
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // for for_each()
void ShowStr(const std::string &);
class Store; // 类前向声明不能在定义之前，使用类成员方法
class Store
{
    private:
        std::ofstream & os;   // 输出文件流对象不可复制，也不可赋值，但可以被引用
    public:
        Store(std::ofstream & fout):os(fout) {}
        void operator() (const std::string & s)
        {
            if (s[0] != '\0')
            {
                int len = s.length();
                os.write((char *) &len, sizeof(std::size_t)); // store length
                os.write(s.data(), len); // store characters
            }
        }
};
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);
int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr)
{
    int len;
    while (fin.read((char *) &len, sizeof(std::size_t)))
    {
        std::string tempstr;
        // 为tempstr分配足够的空间
        tempstr.resize(len); // 当创建一个空的std::string并尝试读取数据到它的data()时，实际上是在写入未分配的内存，这会导致未定义的行为
        fin.read(tempstr.data(), len);
        vistr.push_back(tempstr);
    }
}

void ShowStr(const std::string & s)
{
    std::cout << s << '\n';
}
// c++文件后缀名需要是cpp