#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char firstname[20],lastname[20];
    char name[50];
    cout << "Enter your first name: ";
    cin.getline(firstname,20);
    cout << "Enter your last name: ";
    cin.getline(lastname,20);
    strcat(firstname,", "); // connect two string
    strcat(firstname,lastname);
    strcpy(name,firstname);
    cout << "Here's the information in a single string: " << name;
    return 0;
}