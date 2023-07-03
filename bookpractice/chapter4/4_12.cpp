/*
1、如何声明下述数据
a、actor是由30个char组成的数组。
char actor[30];
b、betsie是由100个short组成的数组
short betsie[100];
c、chuck是由13个float组成的数组
float chuck[13];
d、dipsea是由64个long double 组成的数组。
long double dipsea[64];

2、使用模板类array而不是数组来完成问题1
a、array<char, 30> actor;
b、array<short, 100> betsie;
c、array<float, 13> chuck;
d、array<long double, 64> dipsea;

3、声明一个包含5个元素的int数组，并将它初始化为前5个正奇数
int oddly[5] = {1, 3, 5, 7, 9};

4、编写一条语句，将问题3中数组第一个元素和最后一个元素的和赋给变量even。
int even = oddly[0] + oddly[4]; // 4不能被-1代替

5、编写一个条语句，显示float数组ideas中的第2个元素的值
cout << ideas[1] << "\n";

6、声明一个char的数组，并将其初始化为字符串"chaeesburger"。
char lunch[13] = "cheeseburger";

7、声明一个string对象，并将其初始化为字符串 "Waldor Salad"。
std::string lunch = "Waldor Salad";

8、设计一个描述鱼的结构声明。结构中应包括品种、重量（整数，单位为盎司）和长度（英寸
，包括小数）
struct fish {
    char kind[20];
    int weight;
    float length;
};

9、声明一个问题8中定义的结构的便浪，并对它进行初始化。
fish petes = 
{
    "trout",
    12,
    26.25
};

10、用enum定义一个名为Response的类型， 它包含Yes、No和Maybe等枚举量，其中Yes
的值为1， No的值为0， Maybe为2。
enum Response {No, Yes, Maybe};

11、假设ted是一个double变量，请声明一个指向ted的指针，并使用该指针来显示ted的值。
double * pd = & ted;
cout << * pd << "\n";

12、假设treacle是一个包含10个元素的float数组，请声明一个指向treacle的第一个元素
的指针，并使用该指针来显示数组的第一个元素和最后一个元素。
float * pf = treacle; // or = & treacle[0]
cout << pf[0] << " " << pf[9] << "\n";
    or * pf and * (pf + 9)

13、编写一段代码要求用户输入一个正整数，然后创建一个动态的int数组，其中包含的元素
数目等于用户输入的值。首先使用new来完成这项任务，再使用vector对象来完成这项任务
unsigned in size;
cout << "Enter a positive integer: ";
cin >> size;
int * dyn = new int [size];
vector<int> dv(size);

14、下面的代码是否有效？如果有效，它将打印出什么结果？
cout << (int *) "Home of the jolly bytes";
有效，"Home of the jolly bytes"是一个字符常量，它将判定为字符串开始的地址。
cout对象将char地址解释为打印字符串，但类型转换(int *)将地址转换为int指针，然后
作为地址被打印。该语句打印字符串的地址，只要int类型足够宽，能够存储该地址

15、编写一段代码，给问题8中描述的结构动态分配内存，再读取该结构的成员的值。
struct fish
{
    char kind[20];
    int weight;
    float length;
};
fish * pole = new fish;
cout < "Enter kind of fish: ";
cin >> pole->kind;

16、如果将下面的代码：
cin.getline(address, 80);
替换为：
cin >> address;
将对程序的运行带来什么影响？
使用cin >> address将使得程序跳过空白，直到找到非空字符为止，然后它将读取字符，直到
再次遇到空白为止。因此，它将跳过数字输入后的换行符，从而避免这种问题。另外，它只能读
取一个单词，而不是正行。

17、声明一个vector对象和array对象，他们都将包含10个string对象，指出所需的头文件
，单不要使用using。使用const来指定要包含的string对象数。
#include <string>
#include <vector>
#include <array>
const int Str_num {10}; // or = 10
std::vector<std::string> vstr(Str_num);
std::array<std::string, Str_num> astr; 

*/

