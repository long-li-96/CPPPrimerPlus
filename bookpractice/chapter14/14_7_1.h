#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair {
 private:
  T1 a;
  T2 b;

 public:
  T1& first();
  T2& second();
  T1 first() const { return a; }
  T2 second() const { return b; }
  Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
  Pair() {}
  // void set(const T1& aval, const T2& bval);
  int sum();
  void show(int y);
};

template <class T1, class T2>
T1& Pair<T1, T2>::first() {
  return a;
}

template <class T1, class T2>
T2& Pair<T1, T2>::second() {
  return b;
}
// 辅助函数for Wine::sum
template <class T1, class T2>
int Pair<T1, T2>::sum() {
  return b.sum();
}
// 辅助函数 for Wine::Show()
template <class T1, class T2>
void Pair<T1, T2>::show(int y) {
  for (int i = 0; i < y; i++)
    std::cout << "\t\t" << a[i] << "\t\t" << b[i] << std::endl;
}

// 初始化后重设
// template <class T1, class T2>
// void Pair<T1, T2>::set(const T1& aval, const T2& bval)
// {
//   a = aval;
//   b = bval;
// }

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
 private:
  std::string label;
  PairArray wine_prod_years;
  int save_years;

 public:
  Wine()
      : label("no wine"), wine_prod_years(PairArray({0}, {0})), save_years(0) {}
  // initialize label to l, number of years to y,
  // vintage years to yr[], bottles to bot[]
  Wine(const char* l, int y, const int yr[], const int bot[]);
  // initialize label to l, number of years to y,
  // create array objects of length y
  Wine(const char* l, int y);
  // 根据Wine对象能够存储的几种年份，提示用户输入年份和瓶数
  void GetBottles();
  std::string& Label() { return label; }
  // 返回Pair对象中第二个valarray<int>对象中的瓶数总和
  int sum();
  void Show();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) {
  label = l;
  save_years = y;
  wine_prod_years = PairArray(ArrayInt(yr, y), ArrayInt(bot, y));
}

Wine::Wine(const char* l, int y) {
  label = l;
  save_years = y;
  // wine_prod_years = PairArray(ArrayInt(0,y),ArrayInt(0,y));
}

int Wine::sum() { return wine_prod_years.sum(); }

void Wine::Show() {
  std::cout << "Wine: " << label << std::endl;
  std::cout << "\t\t"
            << "Year"
            << "\t\t"
            << "Bottles" << std::endl;
  wine_prod_years.show(save_years);
}

void Wine::GetBottles() {
  ArrayInt ar1(save_years);
  ArrayInt ar2(save_years);
  std::cout << "Enter " << label << " data for " << save_years << " of year(s)"
            << std::endl;
  for (int i = 0; i < save_years; i++) {
    std::cout << "Enter year: ";
    std::cin >> ar1[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> ar2[i];
  }
  wine_prod_years = PairArray(ar1, ar2);
}

#endif