/*
1、为什么c++有多种整型
可以根据特定需求选择最适合的类型，例如，可以使用short来存储空格，使用long来确保
保存存储容量，也可以寻找可提高特定计算速度的类型。

2、声明与下述描述相符的变量
a、short整数，值为80
short rbis = 80; // or short int rbis = 80;
b、unsigned int 整数，值为42110
unsigned int q = 42110; //  unsigned q = 42110
c、值为3000000000的整数
unsigned long ants = 3000000000; // or long long ants = 3000000000;

3、c++提供了什么措施来防止超出整型的范围？
c++没有提供自动防止超出整数限制的功能，可以使用头文件climits来确定限制情况

4、33L与33之间的区别
常量33L的类型为long，常量33的类型为int

5、下面两条c++语句是否等价？
char grade = 65;
char grade = 'A';
只有在使用ASCII码的系统上，第一条语句才将grade设置为‘A’，第二条语句也适用于使用
其他编码的系统

6、如何使用c++来找出编码88表示的字符？
(1)
char c = 88;
cout << c << endl; // char type prints as character
(2)
cout.put(char(88)); // put() prints char as character
(3)
cout << char(88) << endl; // new-style type cast value to char
(4)
cout << (char)88 << endl; // old-style type cast value to char

7、将long值赋给float变量会导致舍入误差，将long值赋给double变量呢？将long long
值赋给double变量呢？
将long值赋给float变量，如果long为4个字节，则没有损失。最大的long值为20亿，有10位
数，由于double提供了至少13位有效数字，因而不需要进行任何舍入。long long类型可提供
19位有效数字，超过了double保证的13位有效数字。

8、下面c++表达式的结果分别是多少？
a、8 * 9 + 2
74
b、6 * 3 / 4
4
c、3 / 4 * 6
0
d、6.0 * 3 / 4
4.5
e、15 % 4
3

9、假设x1和x2是两个double变量，要将它们作为整数相加，再将结果赋给一个整型变量。请
编写一条完成这项任务的c++语句。如果要将它们作为double值相加并转换为int呢？
（1）
int pos = (int) x1 + (int) x2;
or
int pos = int (x1) + int (x2);
(2)
int pos = (int) (x1 + x2);
or
int pos = int (x1 + x2);

10、下面每条语句声明的变量都是什么类型？
a、auto cars = 15; // int
b、auto iou = 150.37f; // float
c、auto level = 'B'; // char
d、auto crat = U'/U00002155'; // char32_t
e、auto fract = 8.25f/2.5; // double 2.5不加f就是double，最后值取最大精度

整型short至少16位
int至少和short一样长
long至少32位，且至少与int一样长
long long至少64位，且至少与long一样长
*/

/*
运算符优先级：
1、L-R
:: 作用域解析
2、L-R
(表达式) 分组   () 函数调用     () 值构造   [] 数组下标     -> 间接成员运算符   . 直接成员运算符
const_cast 类型转换     dynamic_cast 类型转换   reinterpret_cat 类型转换    static_cast 类型转换
typeid 类型标识     ++ 后缀加1  -- 后缀减1
3、R-L
! 逻辑非    ~ 位非  + 正号  - 负号  ++ 前缀加1  -- 前缀减1  & 地址  * 解除引用  () 类型转换 
sizeof 长度     new 动态内存分配    new[] 动态分配数组  delete 动态释放内存     delete[] 动态释放数组
4、L-R
.* 成员解除引用     ->* 间接成员解除引用
5、L-R
* 乘    / 除    ^ 模
6、L-R
+ 加    - 减
7、L-R
<< 左移     >> 右移
8、L-R
< 小于  <= 小于或等于   >= 大于或等于   > 大于
9、L-R
== 等于     != 不等于
10、L-R
& 按位and
11、L-R
^ 按位异或
12、L-R
｜ 按位or
13、L-R
&& 逻辑and
14、L-R
|| 逻辑or
15、R-L
:? 条件
16、R-L
= 简单赋值  *= 乘并赋值     /= 除并赋值     %= 求模并赋值   += 加并赋值     -= 减并赋值
&= 按位and并赋值    ^= 按位异或并赋值   |= 按位or并赋值     <<= 左移并赋值  >>= 右移并赋值
17、L-R
throw 引发异常
18、L-R
, 将两个表达式合并成一个
*/

/*
基础数据类型
#include <climits> 
定义了符号常量来表示类型的限制,char、整型的最大值、最小值、位数等


1、整型
short 至少16位
int至少与short一样长
long至少32位，且至少与int一样长
long long至少64位，且至少与long一样长

2、
*/