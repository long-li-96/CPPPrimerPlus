#include <iostream>
#include <array>
int main()
{
    using namespace std;
    array<double,10> donations;
    double sum = 0.0,avg = 0.0;
    int count_num = 0, i = 0;
    int count_greater = 0;
    while (cin >> donations[i])
    {
        count_num ++;
        if (count_num > 10)
            break;
        sum += donations[i];
        i++;
    }
    avg = sum/count_num;
    cout << "avg: " << avg << endl;
    i = 0;
    while (i < count_num)
    {
        if (donations[i]>avg)
            count_greater ++;
            i++;
    }
    cout << count_greater << " > " << avg << endl;
    return 0;
}

// 输入一个定长数组，计算得到average，再用数组中元素与average比较得到大于average的元素个数