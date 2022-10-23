// convert age to months
#include <iostream>
int age_to_month(int);
int main()
{
    using namespace std;
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "your month is " << age_to_month(age);
    return 0;
}
int age_to_month(int age)
{
    int month;
    month = 12 * age;
    return month; 
}
