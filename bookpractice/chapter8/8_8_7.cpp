#include <iostream>

template <typename T> // template A
T SumArray(T arr[], int n);

template <typename T> // template B
T SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe",2400.0},
        {"Ura Foxe",1300.0},
        {"Tby Stout",1800.0}
    };
    double * pd[3]; // 指针数组

// set pointers to the amount of the structures in mr_E
    for (int i = 0; i < 3; i ++)
        pd[i] = &(mr_E[i].amount);
    
    cout << "The summary of things is: " << SumArray(things,6)
    << endl;
    cout << "The summary of debts is: " << SumArray(pd,3)
    << endl;
    return 0;
}

template <typename T>
T SumArray(T arr[],int n)
{
    T temp;
    for (int i = 0;i<n;i++)
        temp += arr[i];
    return temp;
}

template <typename T>
T SumArray(T * arr[],int n)
{
    T temp;
    for (int i = 0;i<n;i++)
        temp += *(arr[i]);
    return temp;
}
