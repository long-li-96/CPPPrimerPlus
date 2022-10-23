#include <iostream>
using namespace std;
double cal_records_avg(const int  a[],int number);
void show_records(const int  a[],int number);
void input_records(int a[],int record,int index);

int main()
{
    int records[10];
    int record,amount=0;
    double average;
    cout << "Please enter the records of golf('q' to quit): ";
    for (int i=0;i<10;i++)
    {    
        if (cin >> record)
        {
            input_records(records,record,i);
            amount+=1;
        }
        else 
            break;
    }
    show_records(records,amount);
    average = cal_records_avg(records,amount);
    cout << "The average of recors is: " << average;
    return 0;
}

double cal_records_avg(const int a[],int number)
{
    double sum;
    for(int i = 0;i<number;i++)
    {
        sum+=*(a+i);
    }
    return sum/number;
}

void show_records(const int a[],int number)
{
    for(int i = 0;i<number;i++)
    {
        cout << *(a+i) << " ";
    }
}

void input_records(int a[],int record,int index)
{
    *(a+index) = record;
}