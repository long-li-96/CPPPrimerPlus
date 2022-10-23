#include <iostream>
int main()
{
    using namespace std;
    double income = 0.0;
    double tax = 0.0;
    cout << "Please enter your income and the income tax will be calculated for you: " << endl;
    while (cin >> income && income >= 0)
    {
        if (income <= 5000)
        {
            tax = 0;
            cout << "your tax is " << tax << endl;
            cout << "Please your income again.";
        }
        else if (income > 5000 && income <= 1500)
        {
            tax = (income-5000) * 0.1;
            cout << "your tax is " << tax << endl;
            cout << "Please your income again.";
        }
        else if (income > 15000 && income <= 35000)
        {
            tax = 10000 * 0.1 + (income - 15000) * 0.15;
            cout << "your tax is " << tax << endl;
            cout << "Please your income again.";
        }
        else 
        {
            tax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
            cout << "your tax is " << tax << endl;
            cout << "Please your income again.";
        }
    }
    return 0;
}