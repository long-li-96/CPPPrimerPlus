// using STL functions

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