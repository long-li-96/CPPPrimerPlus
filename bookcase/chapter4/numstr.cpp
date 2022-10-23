// following number input with line input
#include <iostream>
int main()
{
    using namespace std;
    cout << "What year was your houst built?\n";
    int year;
    cin >> year;
    cin.get();
    cout << "What is its street address?\n";
    char address[80];
    //cin >> address;
    cin.getline(address,80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}