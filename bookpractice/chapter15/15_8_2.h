// 使两种异常类型都是从头文件<stdexcept>提供的logic_error类派生出来的类
// 每个what()方法都报告函数名和问题的性质,异常对象不用存储错误的参数值，而只需支持what()方法
// exception classes for hmean(), gmean()

#include <iostream>

#include <stdexcept>
class bad_hmean : public std::logic_error { // logic_error构造函数必须要有string
 private:
  std::string funcname;
 public:
  explicit bad_hmean(const std::string & funn = "none" , const std::string & s = "a == -b"): std::logic_error(s), funcname(funn) {}
  void what();
};

inline void bad_hmean::what()
{
  std::cout << "Exception thrown from function: " << funcname << std::endl;
  std::cout << std::logic_error::what();
}

class bad_gmean : public std::logic_error {
 public:
  std::string funcname;
  bad_gmean(const std::string & funn = "none", const std::string & s = "a < 0 || b < 0") : funcname(funn) , std::logic_error(s) {}
  void what();
};

inline void bad_gmean::what()
{
  std::cout << "Exception thrown from function: " << funcname << std::endl;
  std::cout << std::logic_error::what();
}

