// incore formatting (output)
// 内核格式化：读取string对象中的格式化信息、将格式化信息写入string对象
#include <iostream>
// sstream取代了char数组的strstream.h,定义了ostringstream、istringstream类，这两个类可以用cin、cout的方法
#include <sstream> // 使用与fstream、iostream相同的接口提供程序与string对象之间的I/O
#include <string>

int main()
{
    using namespace std;
    ostringstream outstr; // manage a string stream 将信息写入其中并存储

    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap; // 随机值
    // write formatted information to string stream
    outstr << "The hard disk " << hdisk << " has a capacity of " 
           << cap << " gigabytes.\n"; // 不会在终端打印，这是程序向缓冲区中写入格式化内容
    string result = outstr.str(); // save result 返回一个被初始化为缓冲区内容的字符串对象,该对象被“冻结”不能将信息写入该对象中
    cout << result; // show contents

    return 0;
}