/*
1、考虑下面的类声明：
class RQ1
{
    private:
        char * st; // points to C-style string
    public:
        RQ1() { st = new char []; strcpy(st, ""); }
        RQ1(const char * s)
        { st = new char [strlen(s) + 1]; strcpy(st, s); }
        RQ1(const RQ1 & rq)
        { st = new char [strlen(rq.st) + 1]; strcpy(st, rq.st); }
        ~RQ1() { delete [] st}
        RQ1 & operator={const RQ & rq};
};
将它转换为使用string对象的声明。哪些方法不需要再显示定义？
不再需要显示复制构造函数、析构函数和赋值运算符，因为string对象提供了自己的内存管理功能。

2、在易于使用方法，指出string对象至少两个优于C-风格字符串的地方。
可以将一个string对象赋给另一个。string对象提供了自己的内存管理功能，所以一般不需要担心字符串超出存储容量。

3、编写一个函数，用string对象作为参数，将string对象转换为全部大写。
#include <string>
$include <cctype>
using namespace std;
void ToUpper(string & str)
{
    for (int i = 0; i < str.size(); i ++)
        str[i] = toupper(str[i]);
}

5、如果可以生成一个存储高尔夫球滚（而不是数字）的栈，为何它从概念上说是
一个坏的高尔夫袋子？
栈的LIFO特征（先进后出）意味着可能必须在到达所需要的球棍（club）之前删除很多球棍。

6、为什么说对于逐洞记录高尔夫成绩来说，set容器是糟糕的选择？
集合将只存储每个值的一个拷贝，因此，5个5分将被存储为1个5分

7、既然指针是一个迭代器，为什么STL设计人员没有简单地使用指针来替代
迭代器呢？
使用迭代器使得能够使用接口类似于指针的对象遍历不以数组方式组织的数据，
如双向链表中的数据。

8、为什么STL设计人员仅定义了迭代器基类，而使用继承来派生其他迭代器类型的
类，并根据这些迭代器类来表示算法？
STl方法使得可以将STL函数用于指向常规数组的常规指针以及指向STL容器类的
迭代器，因此提高了通用性

9、给出vector对象比常规数组方便的3个例子
可以将一个vector对象赋给另一个。vector管理自己的内存，因此可以将
元素插入到vector中，并让他自动调整长度。使用at()方法，可以自动检查边界。

10、如果下面程序是使用list而不是vector实现，则该程序哪些部份将是非法的？
非法部份能够轻松修复吗？如果可以，如何修复？
#include <algorithm>  // ?
#include <iostream>
#include <random>
#include <string>
#include <vector>
// 非成员函数swap()可以交换两个类型不同的容器的内容
struct Review {
  std::string title;
  int rating;
};
// 这个容器使用sort()必不可少的函数(适用于容器中的类型元素的操作符)
bool operator<(const Review& r1, const Review& r2);
bool worseThen(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);
int main() {
  using namespace std;
  vector<Review> books;
  Review temp;
  while (FillReview(temp)) books.push_back(temp);
  if (books.size() > 0) {
    cout << "Thank you, You entered the following " << books.size()
         << " ratings: \n"
         << "Rating\tBook\n";
    // 容器指定区间的元素:[begin,end)遍历去作为ShowReview的实参
    // 不可修改容器的内容
    for_each(books.begin(), books.end(), ShowReview); // 等价于：for(auto x: books) ShowReview(x); // 指定引用参数，可以修改容器内容

    // sort()要求容器类可以随机访问
    // 第一个版本的sort()，使用容器元素的<运算符，容器元素是用户自定义对象时，这个对象需要有成员或非成员函数operator<()
    sort(books.begin(),
         books.end());  // 升序排序, 使用为这个容器类型元素定义的operator<()

    cout << "Sorted by rating: \nRating\t Book\n";  
    for_each(books.begin(), books.end(), ShowReview); // 等价于：for(auto x: books) ShowReview(x);
    // random_shuffle(books.begin(), books.end()); // 随机排列books中所有元素,要求books这个容器类可以随机访问
   
    // 第二个版本的sort(),最后一个参数是函数对象
    sort(books.begin(), books.end(),
         worseThen);  // 使用自定义排序函数worseThen等于操作符<
    cout << "Sorted by rating: \nRating\tBook\n";
    // for_each()最后一个参数是函数对象（可以是函数指针等）
    for_each(books.begin(), books.end(), ShowReview); // begin到end-1的每个元素作为入参执行ShowReview

    // 使用随机设备作为随机数生成器的种子
    std::random_device rd;
    // 创建一个梅森旋转引擎的实例
    std::mt19937 g(rd());
    // 使用std:shuffle对容器内元素进行随机排序
    shuffle(books.begin(), books.end(), g);
    cout << "After shuffling: \nRating\tBook\n";
    for_each(books.begin(), books.end(), ShowReview);
  } else
    cout << "No entries. ";
  cout << "Bye.\n";
  return 0;
  // vector<double>::iterator pr; 声明一个迭代器
}
// 全排序
bool operator<(const Review& r1, const Review& r2) {
  if (r1.title < r2.title)
    return true;
  else if (r1.title == r2.title && r1.rating < r2.rating)
    return true;
  else
    return false;
}
// 完整弱排序
bool worseThen(const Review& r1, const Review& r2) {
  if (r1.rating < r2.rating)
    return true;
  else
    return false;
}
bool FillReview(Review& rr) {
  std::cout << "Enter book title (quit to quit): ";
  std::getline(std::cin, rr.title);
  if (rr.title == "quit") return false;
  std::cout << "Enter book rating: ";
  std::cin >> rr.rating;
  if (!std::cin) return false;

  while (std::cin.get() != '\n') continue;
  return true;
}
void ShowReview(const Review& rr) {
  std::cout << rr.rating << "\t" << rr.title << std::endl;
}
这两个vector函数和random_shuffle()函数要求随机访问迭代器，而list只有
双向迭代器。可以使用list模板类的sort()成员函数，而不是通用函数来排序，
但没有与random_shuffle()等效的成员函数.然而，可以将list复制到vector中，
然后打乱vector，并将结果重新复制到list中

11、有函数符TooBig，下面的代码有什么功能？赋给bo的是什么值？
template<class T> 
class TooBig
{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator() (const T & v) {return v > cutoff; }
}
bool bo = TooBig<int> (10) (15); // false


*/