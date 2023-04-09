// using a list
// 双向链表
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm> // for_each

void outint(int n) {std::cout << n << " ";}

int main()
{
    using namespace std;
    list<int> one(5,2); // list of 5 2s 包含5个元素的双向链表，每个元素都初始化为2
    int stuff[5] = {1,2,4,8,6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff+5); // 用数组做迭代器
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more+6); // 将more[0,6)插入three.end()前面

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);

    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);

    three.remove(2); // 删除2的所有实例,线性时间复杂度
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outint);

    three.splice(three.begin(), one); // 将链表one的内容插入到three.begin()的前面,one将为空,固定时间复杂度
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(three.begin(), three.end(), outint);

    three.unique(); // 将连续的相同元素压缩为单个元素，线性时间复杂度
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    three.sort(); // 使用<运算符对链表进行排序，N个元素的复杂度为NlogN
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    two.sort();
    three.merge(two); // 将调用链表three与two合并为调用链表，两个链表必须都已排序，two为空
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    return 0;
}