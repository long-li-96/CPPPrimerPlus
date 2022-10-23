#include <iostream>
using namespace std;
const int Size = 6;
double * Fill_array(double * begin,double * end);
void show_array(double * begin,double * end);
void revalue(double r,double * begin,double * end);
int main()
{
    double numbers[Size];
    double * pt = Fill_array(numbers,numbers+Size-1);
    show_array(numbers,pt);
    if (pt != numbers) // 判断数组是否有数
    {
        cout << "Enter  revaluation factor: ";
        double factor;
        while (!(cin >> factor)) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor,numbers,pt);
        show_array(numbers,pt);
    }
    cout << "Done.\n";
    cin.get();
    return 0;
}
// double * Fill_array(double * begin,double * end)
// {
//     cout << "Please enter the double numbers: " << endl;
//     double * ptr;
//     for (ptr = begin;ptr != end+1;ptr++)
//     {
//         if (!(cin >> *ptr))
//         {
//             break;
//         }
//     }
//     return ptr;
// }
double * Fill_array(double * begin,double * end)
{
    using namespace std;
    double temp;
    double * ptr;
    for (ptr = begin;ptr != end+1;ptr++)
    {
        cout << "Enter value #" << (ptr - begin + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            // bad input
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input;input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *ptr = temp;
    }
    return ptr;
}
void show_array(double * begin,double * end)
{
    cout << "The numbers of array: ";
    double * ptr = begin;
    while (ptr != end)
    {
        cout << * ptr << " ";
        ptr += 1;
    }
    cout << endl;
}
void revalue(double r,double * begin,double * end)
{
   for (double * pt =begin;pt != end;pt++)
   {
       (*pt) *= r;
   }
}