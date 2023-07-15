/*
打开两个文件进行输入，打开一个文件进行输出，将两个输入文件中对应的行拼接起来，
并用空格分隔，将结果写入到输出文件中，如果一个文件比另一个文件短，则将较长
文件中余下的几行直接复制到输出文件中。
*/ 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

// main函数第二个参数必须为char **
int main(int argc,char * argv[]) // second parameter of 'main' (argument array) must be of type 'char **
{
    if (argc < 4)
    {
        std::cerr << "The Number of paramters is not correct!\n";
        exit(EXIT_FAILURE);
    }
    std::string file1 = argv[1]; // 读取的文件1
    std::string file2 = argv[2]; // 读取的文件2
    std::string file3 = argv[3]; // 写入的文件3
    std::string str1, str2; // temparary string
    std::ifstream fin1(file1);
    std::ifstream fin2(file2);
    std::ofstream fout(file3);
    if (!fin1.is_open() || !fin2.is_open())
    {
        std::cerr << "Can't open " << " file for output.\n";
        exit(EXIT_FAILURE); // 打开文件失败，退出程序
    }
    /*
    getline()与eof()组合会有严重的bug
    使用getline读取到文件的最后一行时，如果这一行后没有换行符，eof()返回false,下次循环将再次从文件中
    读取数据，因为已经读到了文件的末尾，getline不会改变参数，结果将最后一行再次写入到了输出文件中。又因为
    eof()返回true才会结束循环,所以会一直在循环写入输出文件
    还有如果用eof()做循环的判断条件，在循环体中用了fin.clear()，会清除文件流的错误标志，eof()又会返回
    false，循环又会继续
    getline()在文件末尾后再尝试读取一行时，这个读取尝试会失败，才设置eof位、fail位
    */

/*
以下这段代码会因为getline已经到了文件末尾，但是读取了文件中的空行，然后再次尝试读取文件末尾再一行而失败，空行
保留在临时变量中，最后输出文件有一空行。
*/

    // while (!fin1.eof() && !fin2.eof())    
    // {
    //     getline(fin1, str1);
    //     fout << str1 << " ";
    //     getline(fin2, str1);
    //     fout << str1 << "\n";
    //     // fin1.clear(); // 会清除文件流的错误标志
    //     // fin2.clear();
    // }
    // std::cout << "fin1.eof() == true or fin2.eof() == true\n";
    // if (fin1.eof())
    // {
    //     fin1.close();
    //     std::cout << "fin1.eof() == true\n";
    //     while (!fin2.eof())
    //     {
    //         getline(fin2, str1);
    //         fout << str1 << "\n";
    //     }
    // }
    // else 
    // {
    //     std::cout << "fin2.eof() == true\n";
    //     fin2.close();
    //     while (!fin1.eof())
    //     {
    //         getline(fin1, str1);
    //         fout << str1 << "\n";
    //     }
    // }

/*
优化版直接调用getline并做判断，检查是否成功，如果失败（即到达文件末尾）就不再将str1写入到文件中
 */

    while (getline(fin1, str1) && getline(fin2, str2))
    {
        fout << str1 << ' ' << str2 << "\n";
    }
    while (getline(fin1, str1))
    {
        fout << str1 << "\n";
    }
    while (getline(fin2, str2))
    {
        fout << str2 << "\n";
    }

    fout.clear();
    fout.close();
    return 0;
}

