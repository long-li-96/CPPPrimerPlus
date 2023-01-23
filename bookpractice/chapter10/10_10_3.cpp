// implementing the Golf class
#include <iostream>
#include <cstring>
#include "10_10_3.h"

Golf::Golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int Golf::setgolf()
{
    char fullname_temp[len];
    int hc_temp;
    using std::cout;
    using std::cin;
    cout << "Please enter name:";
    cin.getline(fullname_temp,len);
    if (strcmp(fullname_temp, "") == 0)
        return 0;
    cout << "Please enter handicap:";
    cin >> hc_temp;
    cin.get();
    *this = Golf(fullname_temp, hc_temp);
    return 1;
}

void Golf::handi(int hc)
{
    handicap = hc;
}

void Golf::showgolf() const
{
    using std::cout;
    cout << "fullname: " << fullname << "\n";
    cout << "handicap: " << handicap << "\n";
}