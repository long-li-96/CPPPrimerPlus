// 从logic_error派生来，报告两个参数值及函数名，程序使用catch捕获异常，每个类都会导致循环结束
#ifndef REPORT_ERROR_H
#define REPORT_ERROR_H
#include <iostream>
#include <stdexcept>
class bad_hmean
    : public std::logic_error {  // logic_error构造函数必须要有string
 private:
  double v1;
  double v2;
  std::string funcname;

 public:
  explicit bad_hmean(double a = 0, double b = 0,
                     const std::string& funn = "none",
                     const std::string& s = "a == -b")
      : std::logic_error(s), funcname(funn), v1(a), v2(b) {}
  void what();
};

inline void bad_hmean::what() {
  std::cout << "Exception thrown from function: " << funcname << std::endl;
  std::cout << "a is " << v1 << ", b is " << v2 << std::endl;
  std::cout << std::logic_error::what();
}

class bad_gmean : public std::logic_error {
 public:
  double v1;
  double v2;
  std::string funcname;
  bad_gmean(double a = 0, double b = 0, const std::string& funn = "none",
            const std::string& s = "a < 0 || b < 0")
      : funcname(funn), std::logic_error(s), v1(a), v2(b) {}
  void what();
};

inline void bad_gmean::what() {
  std::cout << "Exception thrown from function: " << funcname << std::endl;
  std::cout << "a is " << v1 << ", b is " << v2 << std::endl;
  std::cout << std::logic_error::what();
}

#endif