/*
4、如果下面的代码片段是有效程序的组成部份，它将打印什么内容？
int j = 5;
while (++j < 9) // 先+再比较
    cout << j ++ << endl; // 先cout再+
6
8

5、如果下面的代码片段是有效程序的组成部份，它将打印什么内容？
int k = 8;
do 
    cout << " k = " << k << endl;
while (k++ < 5);

k = 8

8、下面的语句是否有效？如果无效，原因是什么？如果有效，它将完成什么工作？
int x = (1,024);
下面的语句又如何呢？
int y;
y = 1,024;
有效，表达式1,024由两个表达式组成--1和024，用逗号运算符连接。值为右侧表达式的值。
这是024，八进制为20，因此该声明将值20赋给x。
有效，因为运算符优先级将导致它被判定成这样：
(y = 1), 024;
左侧表达式将y设置成1，整个表达式的值（没有使用）为024或20（八进制）。

9、在查看输入方面，cin >> ch 同cin.get(ch)和ch = cin.get()有什么不同？
cin >> ch将跳过空格、换行符和制表符，其他两种格式将读取这些字符。

*/