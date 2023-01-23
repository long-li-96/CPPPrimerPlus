// 将函数定义拓展到头文件中
#include "9_6_4.h"
// 函数重载
namespace SALES
{
    void setSales(Sales & s,const double ar[],int n)
    {
        // 如果n <= 0直接设置max等为0，退出函数
        if (n <= 0)
        {
            s.average = 0.0;
            s.max = 0.0;
            s.min = 0.0;
            return;
        }
        // 确保n<=4，Sales.sales只有4个元素
        n = n < 4 ? n:4;
        // 从ar复制元素到s.sales,并依次比较最大值，最小值,计算平均值
        double sum = 0;
        s.max = ar[0];
        s.min = ar[0];
        int i = 0;
        for (; i < n; i ++)
        {
            s.sales[i] = ar[i];
            sum += ar[i];
            s.max = s.max < ar[i] ? ar[i] : s.max;
            s.min = s.min > ar[i] ? ar[i] : s.min;
        }
        s.average = sum / n;
        // 如果n < 4,则s.sales中还有元素未赋值，都赋值为0.0
        for (;i<4;i++)
        {
            s.sales[i] = 0.0;
        }
    }
// 没有考虑输入异常
    void setSales(Sales & s)
    {
        std::cout << "Please enter the value of " << 1 << "st"
        << " quarter's sales: " << std::endl;
        std::cin >> s.sales[0];
        s.max = s.sales[0];
        s.min = s.sales[0];
        double sum = 0.0;
        sum += s.sales[0];
        for (int i = 1; i < 4; i ++)
        {
            std::cout << "Please enter the value of " << i+1 << "st"
            << "quarter's sales: " << std::endl;
            while (! (std::cin >> s.sales[i]))
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << "Please enter again" << std::endl;
            }
            s.max = s.max < s.sales[i] ? s.sales[i] : s.max;
            s.min = s.min > s.sales[i] ? s.sales[i] : s.min;
            sum += s.sales[i];
        }
        s.average = sum / 4;
    }

    void showSales(const Sales & s)
    {
        std::cout << "s.sales: " << std::endl;
        for (int i = 0;i < 4; i ++)
            std::cout << s.sales[i];
        std::cout << std::endl;
        std::cout << s.average << "\n";
        std::cout << s.max << "\n";
        std::cout << s.min << "\n";
    }
}