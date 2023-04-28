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
    two.insert(two.begin(), stuff, stuff+5); // 用数组名做迭代器，将[stuff, stuff+5)的副本插入到two的起始位置
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more+6); // insert将more[0,6)的副本插入three.end()前面即three最后一个元素的后面

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);

    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);

    three.remove(2); // 删除值为2的所有实例,线性时间复杂度
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outint);

    three.splice(three.begin(), one); // 将链表one的内容移动到three.begin()的前面,one将为空,固定时间复杂度，迭代器仍指向原元素
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(three.begin(), three.end(), outint);

    three.unique(); // 将连续的相同元素压缩为单个元素，不相邻的相同元素不会被压缩，线性时间复杂度，先sort再unique可以压缩所有相同元素
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    three.sort(); // 使用<运算符对链表进行排序，N个元素的复杂度为NlogN
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    // 非成员sort函数需要随机访问迭代器，而链表只有双向迭代器，所以不能使用非成员sort函数

    // forward_list是单向链表，每个节点都只链接到下一个节点，只有正向迭代器，是不可反转的容器

    two.sort();
    three.merge(two); // 将调用链表three与two合并为调用链表，两个链表必须都已排序，two为空
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    return 0;
}

// queue、priority_queue、stack的底层类都是vector（默认），也可以是deque或list，但是不能是forward_list，因为forward_list没有back()方法
// array是固定大小的数组,不是stl容器，不能改变大小，但是可以使用swap()方法交换两个array的内容