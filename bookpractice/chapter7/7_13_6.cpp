#include <iostream>
using namespace std;
const int Size = 5;
int Fill_array(double a[], int length);
void show_array(double a[], int length);
void Reverse_array(double a[], int length);

int main()
{
    double numbers[Size];
    int length;
    length = Fill_array(numbers, Size);
    show_array(numbers, length);
    Reverse_array(numbers, length);
    show_array(numbers, length);
    Reverse_array(numbers+1, length-2);
    show_array(numbers, length);
}

int Fill_array(double a[],int length)
{
    cout << "Please enter the double numbers: " << endl;
    int i;
    for (i = 0;i<length;i++)
    {
        if (!(cin >> *(a+i)))
        {
            a[i] = 0;
            return i;
        }
    }
    return i;
}

void show_array(double a[],int length)
{
    cout << "The numbers of array: ";
    for(int i = 0;i<length;i++)
    {
        cout << *(a+i) << " ";
    }
    cout << endl;
}

// void Reverse_array(double a[],int length)
// {
//     double x;
//     for (int i = 0;i<(length/2);i++)
//     {
//         x = *(a+i);
//         *(a+i) = *(a+length-1-i);
//         *(a+length-i-1) = x;
//     }
// }

void Reverse_array(double a[], int length)
{
    double temp;
    for (int i = 0, tail = length - 1; i < tail; i ++, tail --)
    {
        temp = * (a + i);
        * (a + i) = * (a + tail);
        * (a + tail) = temp;
    }
}
