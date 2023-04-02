// introducing the string class
#include <iostream>
#include <string>

// using string constructors

int main()
{
    using namespace std;
    string one("Lottery Winner"); // ctor #1
    cout << one << endl; // overloaded << 
    string two(20, '$'); // ctor #2 重复$20次
    cout << two << endl; 
    string three(one); // ctor #3 复制构造
    cout << three << endl; 
    cout << three << endl;
    one += " Oops!"; // overloaded +=
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';
    string four; // ctor #4
    four = two + three; // overloader +,=
    cout << four << endl;
    char alls[] = "All's well that ends well";
    string five(alls, 20); // ctor #5 初始化为alls前20个字符
    cout << five << endl;
    string six(alls+6, alls +10); // ctor #6 初始化为alls[6,10)
    cout << six << ", ";
    string seven(&five[6], &five[10]); // ctor #6 again 初始化为alls[6,10)
    cout << seven << "...\n";
    string eight(four, 7, 16); // ctor #7 将four的[7,]复制到eight
    cout << eight << " in motion!" << endl;
    return 0;
}