#ifndef WINEP_H_
#define WINEP_H_

#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair {
 private:
  T1 a;
  T2 b;

 public:
  T1 &first();
  T2 &second();
  T1 first() const { return a; }
  T2 second() const { return b; }
  Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
  Pair() {}
  int sum();
  void show(int y);
};

template <class T1, class T2>
T1 &Pair<T1, T2>::first() {
  return a;
}

template <class T1, class T2>
T2 &Pair<T1, T2>::second() {
  return b;
}

// helpful function for Wine::sum()
template <class T1, class T2>
int Pair<T1, T2>::sum() {
  return b.sum();
}

// helpful function for Wine::Show()
template <class T1, class T2>
void Pair<T1, T2>::show(int y) {
  for (int i = 0; i < y; i++)
    std::cout << "\t\t" << a[i] << "\t\t" << b[i] << std::endl;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray {
 private:
  int save_years;

 public:
  Wine() : std::string("no wine"), PairArray({0}, {0}), save_years(0) {}
  Wine(const char *l, int y, const int yr[], const int bot[]);
  Wine(const char *l, int y);
  void GetBottles();
  std::string &Label();
  int sum();
  void Show();
};

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
  save_years = y;
}

Wine::Wine(const char *l, int y) : std::string(l) { save_years = y; }

int Wine::sum() { return PairArray::sum(); }

void Wine::Show() {
  std::cout << "Wine: " << (const std::string &)*this << std::endl;
  std::cout << "\t\t"
            << "Year"
            << "\t\t"
            << "Bottles" << std::endl;
  PairArray::show(save_years);
}

std::string &Wine::Label() { return (std::string &)*this; }

void Wine::GetBottles() {
  ArrayInt ar1(save_years);
  ArrayInt ar2(save_years);
  std::cout << "Enter " << (const std::string &)*this << " data for "
            << save_years << " of year(s)" << std::endl;
  for (int i = 0; i < save_years; i++) {
    std::cout << "Enter year: ";
    std::cin >> ar1[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> ar2[i];
  }
  (PairArray &)*this = PairArray(ar1, ar2);
}

#endif