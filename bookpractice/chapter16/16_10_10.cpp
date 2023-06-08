#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// 单独写智能模板指针的排序函数符，operator<的形参必须是对象，不能是指针

struct Review {
  std::string title;
  int rating;
  double price;
};

// 智能指针对象的比较函数
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

bool titleThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

bool ratingThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

bool priceThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

// 结构对象的函数
bool FillReview(Review& rr);

void ShowReview(const shared_ptr<Review>& rr);

int main() {
  using namespace std;

  vector<shared_ptr<Review> > books;

  // Review temp;

  shared_ptr<Review> temp(new Review);

  while (FillReview(*temp))
  {
    books.push_back(temp);
    temp = make_shared<Review>(); // 创建一个新的 shared_ptr,保证每次往矢量里插入的是被赋新值的指针
  } 
  if (books.size() > 0) {
    cout << "Thank you, You entered the following " << books.size()
         << " ratings: \n"
         << "Rating\tBook\tPrice\n";
    for_each(books.begin(), books.end(), ShowReview);

    // 使用titleThen比较，用来升序排序
    vector<shared_ptr<Review> > booksT(books.begin(),books.end());
    sort(booksT.begin(), booksT.end(),
         titleThen);  
    cout << "Sorted by title: \nRating\tBook\tPrice\n";
    for_each(booksT.begin(), booksT.end(), ShowReview);

    
    vector<shared_ptr<Review> > booksR(books.begin(), books.end());
    // 按rating升序
    sort(booksR.begin(), booksR.end(), ratingThen);
    cout << "Sorted by rating in asc: \nRating\tBook\tPrice\n";
    for_each(booksR.begin(), booksR.end(), ShowReview);
    // 按rating降序
    cout << "Sorted by rating in desc: \nRating\tBook\tPrice\n";
    for_each(booksR.rbegin(), booksR.rend(), ShowReview);

    
    vector<shared_ptr<Review> > booksP(books.begin(),books.end());
    // 按price升序
    sort(booksP.begin(), booksP.end(), priceThen);
    cout << "Sorted by price in asc: \nRating\tBook\tPrice\n";
    for_each(booksP.begin(), booksP.end(), ShowReview);
    cout << "Sorted by price in desc: \nRating\tBook\tPrice\n";
    for_each(booksP.rbegin(), booksP.rend(), ShowReview);
  }
  else 
    cout << "No entries. "; // 每个if-else只有一个else的情况下，省略else必须是return出去或者throw出去
  cout << "Bye.\n";
  return 0;
}

// 全排序 title > rating > price
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
  if (r1->title < r2->title)
    return true;
  else if (r1->title == r2->title && r1->rating < r2->rating)
    return true;
  else if (r1->title == r2->title && r1->rating == r2->rating &&
           r1->price < r2->price)
    return true;
  else
    return false;
}

// title的完整弱排序
bool titleThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
  if (r1->title < r2->title) return false;
  return true;
}

// rating的完整弱排序
bool ratingThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
  if (r1->rating < r2->rating) return false;
  return true;
}

// price的完整弱排序
bool priceThen(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
  if (r1->price < r2->price) return false;
  return true;
}

bool FillReview(Review& rr) {
  std::cout << "Enter book title (quit to quit): ";
  std::getline(std::cin, rr.title);
  if (rr.title == "quit") return false;
  std::cout << "Enter book rating: ";
  std::cin >> rr.rating;
  if (!std::cin) return false;
  while (std::cin.get() != '\n') continue;

  std::cout << "Enter book price: ";
  std::cin >> rr.price;
  if (!std::cin) return false;
  while (std::cin.get() != '\n') continue;

  return true;
}

void ShowReview(const shared_ptr<Review>& rr) {
  std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price
            << std::endl;
}