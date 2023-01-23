#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string firstname,lastname,completename;
    cout << "Enter your first name: ";
    getline(cin,firstname);
    cout << "Enter your last name: ";
    getline(cin,lastname);
    firstname += ", ";
    completename = firstname + lastname; // string可以直接相加，char * 不行
    cout << "Here's the information in a single string: " << completename;
    return 0; 
}