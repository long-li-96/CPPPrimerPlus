#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string month[12] = 
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int sales_volume[3][12],sum_3y = 0,sum[3]={0,0,0};
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << "Please enter the sales volume in " << month[j] << "of the " << i+1 << "st year" << endl;
            cin >> sales_volume[i][j];
            sum_3y += sales_volume[i][j];
            sum[i] += sales_volume[i][j];
        }
    }
    for (int k = 1;k<4;k++)
        cout << "The sales volume in " << k << "st year is" << sum[k-1] << endl;
    cout << "The total sales volume in three years is " << sum_3y;
    return 0;
}