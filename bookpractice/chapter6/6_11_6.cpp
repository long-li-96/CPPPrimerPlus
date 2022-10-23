#include <iostream>
#include <string>
using namespace std;
struct contribution{
    string name;
    double payment;
};
int main()
{
    int num;
    cout << "Please enter the number of donors: ";
    cin >> num;
    contribution * contributions = new contribution [num]; //动态分配结构数组的指针
    for (int i = 0;i<num; i++)
    {
        cout << "please enter the name of donor: ";
        cin >> (contributions+i)->name;
        cout << "please enter the payment of donor: ";
        cin >> (contributions+i)->payment;
    }
    int sum_g=0,sum_l=0;
    cout << "Grand patrons: " << endl;
    for (int i = 0;i<num;i++)
    {
        if ((contributions+i)->payment > 1000)
        {
            sum_g++;
            cout << (contributions+i)->name << endl;
            cout << (contributions+i)->payment << endl;
        }
    }
    if (sum_g == 0)
            cout << "None";
    cout << "patrons: " << endl;
    for (int i = 0;i<num;i++)
    {
        if ((contributions+i)->payment <= 1000)
        {
            sum_l++;
            cout << (contributions+i)->name << endl;
            cout << (contributions+i)->payment << endl;
        }
    }
    if (sum_l == 0)
            cout << "None";
    delete [] contributions;
    return 0;
}