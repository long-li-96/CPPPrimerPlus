// using the delete operator 接收字符串，节省内存
#include <iostream>
#include <cstring>
using namespace std;
char * getname(void); // function prototype 函数原型
int main()
{
    char * name; // create pointer but no storage

    name = getname(); // assign address of string to name
    cout << name << " at " << (int *) name << "\n";
    delete [] name; // memory freed again
      
    name = getname(); // assign address of string to name
    cout << name << " at " << (int *) name << "\n"; // display address of name
    delete [] name; // memory freed again
    return 0;
}
char * getname()
{
    char temp[80]; // temporary storage 暂时存储
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp); // copy string into smaller space 不检查改内存块是否能容纳

    return pn; // temp lost when functiion ends
}
