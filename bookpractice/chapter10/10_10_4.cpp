// implementing the Sales class
#include <iostream>
#include "10_10_4.h"

namespace SALES
{
    using std::cout;
    using std::cin;

    Sales::Sales()
    {
        for (int i = 0; i < QUARTERS; i++)
            sales[i] = 0.0;
        average = 0.0;
        max = 0.0;
        min = 0.0;
    }

    Sales::Sales(const double ar[], int n)
    {
        if (n <= 0)
        {
            average = 0.0;
            max = 0.0;
            min = 0.0;
            for (int i = 0; i < QUARTERS; i ++)
                sales[i] = 0.0;
        }
        // 确保n<=QUARTERS，Sales.sales只有QUARTERS个元素
        n = n < QUARTERS ? n:QUARTERS;
        // 从ar复制元素到sales,并依次比较最大值，最小值,计算平均值
        double sum = 0;
        max = ar[0];
        min = ar[0];
        int i = 0;
        for (; i < n; i ++) // 从ar复制数组元素值时顺带比较最大值、最小值
        {
            sales[i] = ar[i];
            sum += ar[i];
            max = max < ar[i] ? ar[i]:max;
            min = min > ar[i] ? ar[i]:min;
        }
        average = sum/n;
        // 如果n < QUARTERS,则sales中还有元素未赋值，都赋值为0.0
        for (;i < QUARTERS; i ++)
            sales[i] = 0.0;
    }

    void Sales::show() const
    {
        cout << "sales: " << "\n";
        for (int i = 0; i < QUARTERS; i ++)
            cout << sales[i] << " ";
        cout << "\n";
        cout << average << "\n";
        cout << max << "\n";
        cout << min << "\n";
    }

    void Sales::setSales()
    {
        double ar[QUARTERS];
        int i;
        for (i = 0; i < QUARTERS; i ++)
        {
            cout << "Enter the #" << i + 1 << " number: (q to quit)";
            if (!(cin >> ar[i])) // 非法输入，结束循环
                break;
        }
        if (i == 0) // 如果一次都没有输入成功
            ar[0] = 0.0;
        * this = Sales(ar, i); // 自身对象调用另一个构造函数
    }
}