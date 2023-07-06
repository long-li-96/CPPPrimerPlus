/*
1、请看下面两个计算空格和换行符数目的代码片段：
// version1
while (cin.get(ch)) // quit on eof
{
    if (ch == ' ')
        spaces++;
    if (ch == '\n')
        newlines ++;
}
// version2
while (cin.get(ch)) // quit on eof
{
    if (ch == ' ')
        spaces++;
    else if (ch == '\n')
        newlines ++;
}
第二种格式比第一种格式好在哪里呢？
两个版本答案相同，但if else版本的效率更高。例如，考虑当ch为空格时的情况。版本1对空格
加1，然后看她是否为换行符。这将浪费时间，因为程序已经知道ch为空格，不需要再往下
判断，因此它不是换行符。在这种情况下，版本2将不会查看字符是否为换行符。

2、用ch+1替换++ch在打印时将发生什么情况？
++ch 和 ch+1得到的数值相同。但++ch的类型为char，将作为字符打印，而ch+1是int类型
（因为将char和int相加），将作为数字打印。

3、表达式ch = $的值为$字符的编码

4、创建表示下述条件的逻辑表达式
d. x为偶数，但不是26的倍数.
x % 2 == 0 && !(x % 26 == 0);
f.ch是小写字母或大写字母
(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')

5、在c++中，!!x是否与x相同？
不一定，如果x为10，则!x为0，!!x为1。如果x为bool变量，则!!x为x。

6、创建一个条件表达式，其值为变量的绝对值。也就是说，如果变量x为正，则表达式值为x；
假如x为负，则表达式值为-x
(x < 0) ? -x : x
or
(x > 0) ? x : -x

7、用switch改写下面的代码片段：
if (ch == 'A')
    a_grade ++;
else if (ch == 'B')
    b_grade ++;
else if (ch == 'C')
    c_grade ++;
else if (ch == 'D')
    d_grade ++;
else
    f_grade ++;
//switch改写
switch(ch)
{
    case 'A': a_grade ++;
        break;
    case 'B': b_grade ++;
        break;
    case 'C': c_grade ++;
        break;
    case 'D': d_grade ++;
        break;
    default: f_grade ++;
        break;
}

8、switch：与使用数字相比，使用字符(如a和c)表示菜单选项和case标签有何优点？
如果使用整数标签,且用户输入了非整数，则程序将因为整数输入不能处理字符而挂起。
但是，如果使用字符标签，而用户输入了整数，则字符输入将整数作为字符处理。然后switch
语句的default部份将继续执行。

9、请重写下面的代码片段，不要使用break和continue语句：
int line = 0;
char ch;
while (cin.get(ch))
{
    if (ch == 'Q')
        break;
    if (ch != '\n')
        continue;
    line ++;
}
// 改写
int line = 0;
char ch;
while (cin.get(ch) && ch !='Q')
{
    if (ch == '\n')
        line ++;
}


*/