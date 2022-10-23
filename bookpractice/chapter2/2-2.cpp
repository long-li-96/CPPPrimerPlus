// convert long to yard, 1 long = 220 yard
#include <iostream>
double long_to_yard(double); //function prototype of longtoyard()
int main()
{
    using namespace std;
    cout << "Please enter the number of long" << endl;
    double longnumber;
    cin >> longnumber;
    double yardnumber = long_to_yard(longnumber);
    cout << longnumber << " long = " << yardnumber << " yard." << endl;
    return 0;
}
double long_to_yard(double longnumber) //define the function longtoyard()
{
    double yardnumber = 220 * longnumber;
    return yardnumber;
}