#include <iostream>
#include <string>
using namespace std;
struct car{
    string name;
    int year;
};
int main()
{
    int num;
    cout << "How many cars do you wish to catalog?" << endl;
    cin >> num;
    cin.get(); // 捕获换行符
    car * cars = new car [num];
    for (int i = 0; i < num; i ++)
    {   
        cout << "Car #" << i+1 << ":" << endl;
        cout << "Please enter the make: ";
        getline(cin, (cars+i)->name); // string input: getline(cin, string)
        cout << "Please enter the year made: ";
        cin >> (cars+i)->year;
        cin.get();
    }
    cout << "Here is your collection: " << endl;
    for (int j = 0;j < num;j++)
        cout << (cars+j)->year << " " << (cars+j)->name << endl;
    delete [] cars;
    return 0;
}