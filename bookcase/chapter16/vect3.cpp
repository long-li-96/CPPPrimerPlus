// using STL functions

#include <algorithm>  // ?
#include <iostream>
#include <random>
#include <string>
#include <vector>

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
    for_each(books.begin(), books.end(), ShowReview);

    sort(books.begin(),
         books.end());  // 升序排序, 使用为这个容器类型元素定义的operator<()

    cout << "Sorted by rating: \nRating\t Book\n";
    for_each(books.begin(), books.end(), ShowReview);

    sort(books.begin(), books.end(),
         worseThen);  // 使用自定义排序函数worseThen等于操作符<
    cout << "Sorted by rating: \nRating\tBook\n";
    for_each(books.begin(), books.end(), ShowReview);

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

bool operator<(const Review& r1, const Review& r2) {
  if (r1.title < r2.title)
    return true;
  else if (r1.title == r2.title && r1.rating < r2.rating)
    return true;
  else
    return false;
}

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