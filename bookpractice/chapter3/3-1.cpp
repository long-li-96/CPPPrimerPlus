// convert inches to feet
#include  <iostream>
using namespace std;
const int inches_per_feet = 12;

void inches_to_feet(int);

int main()
{
    cout << "Please enter your height by inches:________\b\b\b\b\b\b\b\b";
    int height_inches;
    cin >> height_inches;
    inches_to_feet(height_inches);
    return 0;
}

void inches_to_feet(int height_inches)
{
    int feet = height_inches / inches_per_feet;
    int inches = height_inches % inches_per_feet;
    cout << "your height is " << feet << " feet " << inches << " inches";
}