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
*/