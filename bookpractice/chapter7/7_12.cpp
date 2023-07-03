/*
1、使用函数的3个步骤是什么
提供原型、定义函数、调用函数

2、请创建于下面描述匹配的函数原型。
a、igor()没有参数且没有返回值
void igor(void);
b、tofu()接受一个int参数，并返回一个float
float tofu(int);
c、mpg()接受两个double参数，并返回一个double。
double mpg(double d1, double d2);
d、summation()将long数组名和数组长度作为参数，并返回一个long值
long summation(long harray[], int size);
e、doctor()接受一个字符串参数(不能修改该字符串)，并返回一个double值。
double doctor(const char * str);
f、ofcourse()将boss结构作为参数，不返回值
void ofcourse(boss dude);
g、plot()将map结构的指针作为参数，并返回一个字符串
char * plot(map * pmap);

3、编写一个接受3个参数的函数：int数组名、数组长度和一个int值，并将数组的所有元素
都设置为该int值。
void set_array(int arr[], int  size, int value)
{
    for (int i = 0; i < size; i ++)
        arr[i] = value;
}

4、编写一个接受3个参数的函数：执行数组区间中第一个元素的指针、指向数组区间最后一个
元素后面的指针以及一个int值，并将数组中的每一个元素都设置为该int值
void set_array(int * begin, int * end, int value)
{
    for (int * pt = begin; pt != end; pt++)
        * pt = value;
}

5、编写将double数组名和数组长度作为参数，并返回该数组中最大值的函数，该函数不应修改
数组的内容。
double biggest (const double foot[], int size)
{
    double max;
    if (size < 1)
    {
        cout << "Invalid array size of " << size << endl;
        cout << "Returning a value of 0\n";
        return 0;
    }
    else 
    {
        max = foot[0];
        for (int i = 1; i < size; i ++)
        {
            if (foot[i] > max)
                max = foot[i];
        }
        return max;
    }
}

6、为什么不对类型为基本类型的函数参数使用const限定符？
将const限定符用于指针，以防止指向的原始数据被修改。程序传递基本类型时，它将按值传递，
以便函数使用副本。这样，原始数据将得到保护。

7、c++程序可使用哪3种C-风格的字符串格式？
char数组、“”、字符串第一个字符的指针

8、编写一个函数，其原型如下：
int replace(char * str, char c1, char c2);
该函数将字符串中所有的c1都替换为c2，并返回替换次数。
int replace (char * str, char c1, char c2)
{
    int count = 0;
    while (* str) // while not at end of string
    {
        if ( * str == c1)
        {
            * str = c2;
            count ++;
        }
        str ++; // advance to next character
    }
    return count;
}

9、表达式* "pizza"的含义是什么？"taco"[2]呢？
由于c++将“pizaa”解释为其第一个元素的地址，因此使用*运算符将得到第一个元素的值，即
字符p。由于c++将"taco"解释为第一个元素的地址，因此它将"taco"[2]解释为第"2"个元素的值，
即字符c。字符串常量的行为与数组名相同。

10、c++允许按值传递接哦股，也允许传递结构的地址。如果glitz是一个结构变量，如何按值
传递它？如何传递它的地址？这两种方法有何利弊？
按值传递：glitz，访问成员.
传递地址：&glitz,访问成员->
按值传递将自动保护原始数据，但这是以时间和内存为代价的，按地址传递可以节省时间和内存，但
不能保护原始数据，除非对函数参数使用了const限定符。

11、函数judge()的返回类型为int，它将这样一个函数的地址作为参数：将const char指针作为参数，
并返回一个int值。请编写judge()函数的原型。
int judge( int (* pf) (const char *)) // 写法：把函数原型作为参数写进去，只是函数名用指针表示

12、假设有如下结构声明：
struct applicant
{
    char name[30];
    int credit_ratings[3];
};
a、编写一个函数，它将applicant结构作为参数，并显示该结构的内容。
void show(applicant ap)
{
    cout << ap.name << endl;
    for (int i = 0; i < 3; i ++)
        cout << ap.credit_ratings[i] << endl;
}
b、编写一个函数，它将applicant结构的地址作为参数，并显示该参数执行的结构的内容。
void show(const applicant * pa)
{
    cout << pa->name << endl;
    for (int i = 0; i < 3; i ++)
        cout << pa->credit_ratings[i] << endl;
}

13、假设函数f1()和f2()的原型如下：
void f1(applicant * a);
const char * f2(const applicant * a1, const applicant * a2);
请将p1和p2分别声明为指向f1和f2的指针；将ap声明为一个数组，它包含5个类型与p1相同的
指针；将pa声明为一个指针，它指向的数组包含10个类型与p2相同的指针。使用typedef来帮助
完成这项工作。
typedef void (* p_f1) (applicant * pa); // p_f1被简化声明为函数指针类型
p_f1 p1 = f1;
typedef const char * (*p_f2)(const applicant *, const applicant *); // p_f2被简化声明为函数指针类型
p_f2 p2 = f2;
p_f1 ap[5];
p_f2 (* pa)[10];

*/