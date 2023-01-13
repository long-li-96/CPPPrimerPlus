// line input
#include <iostream>
#include <string>
#include <cstring> // C-style string library
int main()
{
    using namespace std;
    char charr[20];
    string str;

    cout << "Length of string in charr before input:"
         << strlen(charr) << endl; // std::strlen in cstring
    cout << "Length of string in str before input:"
         << str.size() << endl; // string方法得到字符数
    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length
    cout << "You entered: " << charr << endl;
    cout << "Enter another line of text:\n";
    getline(cin, str); // cin now an argument; no length specifier string的输入方法
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: "
         << strlen(charr) << endl;
    cout << "Length of string in str after input: "
         << str.size() << endl;
     // mac上编译目前必须 g++ -std=c++11 file.cpp -o program
     char * cout_str = R"(Jim "King" Try uses "\n" instead of endl. )";
    cout << cout_str << "\n";
    return 0;
}