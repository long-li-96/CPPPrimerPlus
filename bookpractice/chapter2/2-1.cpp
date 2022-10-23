// display your name and address
#include <iostream>
int main()
{
    using namespace std;
    cout << "Please enter your name." << endl;
    char name[20];
    char address[40];
    cin.getline(name,20); //以enter结束流的输入而不是空格
    cout << "Continue to enter your address." << endl;
    cin.getline(address,40);
    cout << "Your name is " << name << ", and your address is " << address << endl;
    return 0;
}