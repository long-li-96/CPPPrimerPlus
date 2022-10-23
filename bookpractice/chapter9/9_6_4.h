#include <iostream>

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the
    // average,maximum,and minimum values of the entered items;
    // remaining elements of sales,if any,set to 0
    // 从ar复制不多于4个元素到s，计算并存储平均值、最大值、最小值，
    // n < 4 则将剩余的sales元素置为0.0 
    void setSales(Sales & s,const double ar[],int n);

    // gathers sales for 4 quarters interactively, stores them 
    // in the sales member of s and computes and stores the
    // average,maximum,and minimum values
    // 互动获取4个季度的sales，存储到s中，并计算和存储最大值、最小值、平均值
    void setSales(Sales & s);

    // display all informatioon in structure s
    void showSales(const Sales & s);
}

