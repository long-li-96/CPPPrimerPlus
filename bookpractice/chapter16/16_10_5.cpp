// 使用STL函数重写template<class T> int reduce(T ar[],int n); // ar数组名，n元素个数
// 排序，删除重复的值，返回缩减后元素的数目
// 改成模板函数

#include <iostream>
#include <algorithm>
#include <set>

template <class T> 
int reduce(T ar[], int n);

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

template <class T>
int reduce(T ar[], int n)
{
    std::set<T> setT(ar, ar+n);
    return setT.size();
}
