// using lambda expressions
// 使用lambda表达式
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long Size1 = 39L;
const long Size2 = 100*Size1;
const long Size3 = 100 * Size2;
bool f3(int x) { return x % 3 == 0;}
bool f13(int x) {return x % 13 == 0;}

int main()
{
    using std::cout;
    std::vector<int> numbers(Size1); // Size1 个int元素的vector

    std::srand(std::time(0)); // 随机种子
    std::generate(numbers.begin(), numbers.end(), std::rand); // 将numbers填充为随机数

    // using function pointers
    cout << "Sample size = " << Size1 << '\n';

    int count3 = std::count_if(numbers.begin(), numbers.end(), f3); // 统计能被3整除的元素个数
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number  of numbers
    numbers.resize(Size2); // vector重设容量
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    // using a functor 函数对象
    class f_mod
    {
        private:
            int dv;
        public:
            f_mod(int d = 1) : dv(d) {}
            bool operator() (int x) {return x % dv == 0;}
    };

    count3 = std::count_if (numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

    // increase number of numbers again
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';
    
    // using lambdas
    count3 = std::count_if(numbers.begin(), numbers.end(), 
             [](int x){return x % 3 == 0;}); // lambda表达式
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), 
              [](int x) {return x % 13 == 0;});
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    return 0;
}