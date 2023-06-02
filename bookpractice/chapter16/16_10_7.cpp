// 彩票卡游戏，卡片有带编号的圆点，圆点被随机选中，lotto函数，接受卡片上圆点的个数、选中的
// 圆点个数，返回vector<int>对象，包含排列后选择的号码
// vector<int> winners = Lotto(51, 6)
// 用rand()无法完成，会生成重复值，创建一个包含所有可能值的矢量，使用random_shuffle()
// 通过打乱后矢量的第一个值来取值
// 使用std::shuffle()代替random_shuffle()

#include <iostream>
#include <vector>
#include <ctime>
#include <random>   // for random_device mt19937 shuffle
#include <iterator> // for ostream_iterator
std::vector<int> Lotton(int num1, int num2);

int main()
{
    std::ostream_iterator<int, char> out_iter(std::cout, "\n");
    std::vector<int> lotton = Lotton(100, 10);
    std::copy(lotton.begin(),lotton.end(), out_iter); // 这里不能用for_each，因为out_iter不是函数对象
    return 0;
}

// 使用不重复的矢量来随机取值，这才是真的不重复
std::vector<int> Lotton(int num1,int num2)
{
    // 创建包含所有可能值的矢量
    std::vector<int> allValues(num1);
    for (int i = 0; i < num1; i ++)
    {
        allValues.push_back(i);
    }

    // 使用随机数引擎和std::shuffle()打乱矢量
    std::random_device rd; // 生成种子
    std::mt19937 g(rd()); // 随机数引擎
    std::shuffle(allValues.begin(), allValues.end(), g); // 就地随机排序

    // 选取打乱后矢量的前num2个值作为结果返回
    std::vector<int> result(allValues.begin(), allValues.begin()+num2); // 左闭右开

    return result;
}

/* 以下这种方案不行，还是会重复 
// 这里使用随机数引擎、整数分布函数代替
std::vector<int> Lotton(int num1, int num2)
{
    // 将随机数引擎对象、分布函数对象声明为静态变量，已确保他们在函数调用之间保持状态
    // 从而实现在一次函数运行期间内生成不同的随机数
    // 创建随机数引擎
    static std::random_device rd;
    static std::mt19937 g(rd());

    // 创建静态整数分布函数
    static std::uniform_int_distribution<int> dist;

    // 设置随机数范围
    dist.param(std::uniform_int_distribution<int>::param_type(0, num1+1)); // 左闭右开

    // 创建指定元素数目的vector对象
    std::vector<int> nums(num2);

    // 遍历vector赋值随机数
    for (std::vector<int>::iterator pr = nums.begin(); pr != nums.end(); pr++)
    {
        *pr = dist(g);
    }
    return nums;
}
*/
