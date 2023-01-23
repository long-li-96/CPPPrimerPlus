// a
// #include <iostream>
// using namespace std;
// const int Seasons = 4;
// const char * str[Seasons] = {"Spring","Summer","Fall","Winter"}; //指针数组表示字符串数组
// // prototype
// void fill(double a[],int num);
// void show(double a[],int num);
// int main()
// {
//     double expenses[Seasons];
//     fill(expenses,Seasons);
//     show(expenses,Seasons);
//     return 0;
// }

// void fill(double a[],int num)
// {
//     for (int i = 0;i<num;i++)
//     {
//         cout << "Enter " << " expenses: ";
//         cin >> *(a+i);
//     }
// }
// void show(double a[],int num)
// {
//     double total = 0.0;
//     for (int i = 0;i<num;i++)
//     {
//         cout << *(str+i) << ": $" << *(a+i) << endl;
//         total += *(a+i); 
//     }
//     cout << "Total Expenses: $" << total << endl;
// }

//b
// 不能直接传结构名而不返回，因为形参接收实参的值，不会改变实参
#include <iostream>
using namespace std;
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring","Summer","Fall","Winter"}; // 字符指针数组才能在一个数组中放多个字符串（指针）
struct Seasons_Expenses{
    double expenses[Seasons];
};
// prototype
void fill(Seasons_Expenses * a,int num);
void show(const Seasons_Expenses * a,int num);
int main()
{
    Seasons_Expenses a;
    fill(&a,Seasons);
    show(&a,Seasons);
    return 0;
}
void fill(Seasons_Expenses * a, int num) // 直接改变了原有指针指向的数据
{
    for (int i = 0; i<num; i++)
    {
        cout << "Enter " << *(Snames+i) << " expenses: ";
        cin >> a->expenses[i];
    }
}
void show(const Seasons_Expenses * a,int num)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < num; i++)
    {
        cout << *(Snames+i) << ": $" << a->expenses[i] << endl;
        total += a->expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

