// 使用STL函数重写int reduce(long ar[],int n); // ar数组名，n元素个数
// 排序，删除重复的值，返回缩减后元素的数目
#include <iostream>
#include <algorithm>
#include <set>

int reduce (long ar[], int n);

int main()
{
    long ar[5] = {
        1,
        2,
        3,
        2,
        1
    };

    std::cout << std::to_string(reduce(ar,5)); // 将数字转换为字符串
    return 0;
}


int reduce(long ar[], int n)
{
    std::set<long> setLong(ar, ar+n);
    // std::sort(setLong.begin(), setLong.end()); // set不提供随机访问迭代器，所以不支持sort函数
    return setLong.size();
}