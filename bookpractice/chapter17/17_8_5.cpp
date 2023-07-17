/* 
Mat 和 Pat想邀请他们的朋友来参加派对，就像第16章中的编程练习8那样，但现在他们希望
使用文件。他们请您编写一个完成下述任务的程序。
· 从文本文件mat.dat中读取Mat朋友的姓名清单，其中每行为一个朋友。姓名将被存储在
容器，然后按顺序显示出来。
· 从文本文件pat.dat中读取Pat朋友的姓名清单，其中每行为一个朋友。姓名将被存储在
容器中，然后按顺序显示出来。
· 合并两个清单，删除重复的条目，并将结果保存在文件matnpat.dat中，其中每行为一个朋友
*/ 
// multiset允许元素重复，对插入的元素自动根据红黑树排序
#include <set>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib> // for exit()

int main(int argc, char * argv[]) // 第一个参数为命令名，argc为命令行参数个数，argv为指针数组
{
    if (argc != 4)
    {
        std::cerr << "The NUmber of paramters is not correct!";
        exit(EXIT_FAILURE);
    }

    std::string file1 = argv[1]; // 读取的文件1
    std::string file2 = argv[2]; // 读取的文件2
    std::string file3 = argv[3]; // 写入的文件3
    std::multiset<std::string> mat;
    std::multiset<std::string> pat;
    std::multiset<std::string> strUnion;
    std::ostream_iterator<std::string, char> out(std::cout, "\n");
    std::string tempStr;
    std::ifstream fin;
    fin.open(file1);
    if (!fin.is_open())
    {
        std::cerr << "Could not open " << file1 << std::endl;
        fin.clear();
    }
    else
    {
        while (std::getline(fin, tempStr))
        {
            mat.insert(tempStr);
        }
        fin.clear();
        fin.close();
    }
    std::copy(mat.begin(), mat.end(), out);
    fin.open(file2);
    if (!fin.is_open())
    {
        std::cerr << "Could not open " << file2 << std::endl;
        fin.clear();
    }
    else
    {
        while (std::getline(fin, tempStr))
        {
            pat.insert(tempStr);
        }
        fin.clear();
        fin.close();
    }
    std::copy(pat.begin(), pat.end(), out);
    std::set_union(mat.begin(),mat.end(), pat.begin(),
    pat.end(), std::insert_iterator<std::multiset<std::string> > (strUnion, strUnion.begin()));
    std::copy(strUnion.begin(), strUnion.end(), out);
    std::ofstream fout(file3, std::ios::out | std::ios::app);
    for (auto p = strUnion.begin(); p != strUnion.end(); p ++)
    {
        fout << * p << '\n';
    }
    fout.clear();
    fout.close();
    if (!fout.good())
    {
        std::cerr << "Error occurred when writing to file " << file3 << "\n";
    }
    return 0;
}