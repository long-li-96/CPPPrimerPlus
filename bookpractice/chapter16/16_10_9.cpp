// 优化链表排序
// 相对于数组，在链表中添加和删除元素更容易，但排序速度更慢，这就引出了一种可能性：相对于
// 使用链表算法进行排序，将链表复制到数组中，对数组排序，再将排序后的结果复制到链表中
// 的速度可能更快，但这也可能占用更多的内存。请使用如下方法检验上述假设。
// a 创建大型vector<int>对象vi0，并使用rand()给它提供初始值
// b 创建vector<int>对象vi 和 list<int>对象li，它们的长度和初始值与vi0相同
// c 计算使用STL算法sort()对vi进行排序所需的时间，再计算使用list的方法sort()对li进行排序所需要的时间
// d 将li重置为排序的vi0的内容，并计算执行如下操作所需的时间：将li的内容复制到vi中，对vi进行排序，并将结果复制到li中。
// 计算操作所需时间，可使用ctime库中的clock()，如waitting.cpp使用clock_t start = clock()来获取开始时间
// 操作结束后，使用clock_t end = clock(); double (end - start) / CLOCKS_PER_SEC来获取操作时间
// 结果取决于很多因素如可用内存量、是否支持多处理以及数组(列表)的长度.编译器提供了默认生成方式
// 和发布生成方式，则使用发布生成（命令行参数：-O2）

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <random> // for random_device mt19937 shuffle uniform_int_distribution
#include <iomanip>

const int  maxnum = 100000000;

// a 创建大型vector<int>对象vi0，并使用rand()给它提供初始值
std::vector<int> createVi(int num);

// 计算使用STL算法sort()对vi进行排序所需的时间
double timeSortVi(std::vector<int> & vi);

// 计算使用list的方法sort()对li进行排序所需要的时间
double timeListSort(std::list<int> & li);

// 计算执行如下操作所需的时间：将li的内容复制到vi中，对vi进行排序，并将结果复制到li中。
double viSortToList(std::list<int> & li, std::vector<int> & vi);

int main()
{
    // 创建随机数引擎
    std::random_device rd;
    std::mt19937 g(rd());

    // 设置全局输出精度为15位
    std::cout.precision(15);

    // a 创建大型vector<int>对象vi0，并使用rand()给它提供初始值
    std::vector<int> vi0 = createVi(maxnum);
    // b 创建vector<int>对象vi 和 list<int>对象li，它们的长度和初始值与vi0相同
    std::vector<int> vi(vi0);
    std::list<int> li(vi0.begin(), vi0.end()); // 使用list构造函数的范围初始化
    std::cout << "使用STL算法sort()对vi进行排序所需的时间: " << timeSortVi(vi) << std::endl;
    std::shuffle(vi.begin(), vi.end(), g); // 就地随机排序
    std::cout << "计算使用list的方法sort()对li进行排序所需要的时间: " << timeListSort(li) << std::endl;
    std::copy(vi0.begin(), vi0.end(), li.begin());
    std::cout << "将li的内容复制到vi中，对vi进行排序，并将结果复制到li中所需要的时间：" << viSortToList(li,vi) << std::endl;
    return 0;
}

std::vector<int> createVi(int num)
{
    // 创建随机数引擎
    std::random_device rd; // 生成种子
    std::mt19937 g(rd());
    // 创建静态整数分布函数
    std::uniform_int_distribution<int> dist;
    // 设置随机数范围
    dist.param(std::uniform_int_distribution<int>::param_type(0, num + 1)); // 左闭右开
    // 创建指定元素数目的vector对象
    std::vector<int> nums(num);

    // 遍历vector赋值随机数
    for (std::vector<int>::iterator pr = nums.begin(); pr != nums.end(); pr++)
    {
        *pr = dist(g);
    }
    return nums;
}

double timeSortVi(std::vector<int> & vi)
{
    std::clock_t start = std::clock();
    std::sort(vi.begin(), vi.end());
    std::clock_t end = std::clock();
    return double(double(end-start)/ CLOCKS_PER_SEC);
}

double timeListSort(std::list<int> & li)
{
    std::clock_t start = std::clock();
    li.sort();
    std::clock_t end = std::clock();
    return double(double(end-start)/ CLOCKS_PER_SEC);
}

double viSortToList(std::list<int> & li, std::vector<int> & vi)
{
    std::clock_t start = std::clock();
    // 将li的内容复制到vi中
    std::copy(li.begin(),li.end(), vi.begin());
    // 对vi进行排序，并将结果复制到li中
    std::sort(vi.begin(),vi.end());
    std::copy(vi.begin(), vi.end(), li.begin());
    std::clock_t end = std::clock();
    return double(double(end-start) / CLOCKS_PER_SEC );
}