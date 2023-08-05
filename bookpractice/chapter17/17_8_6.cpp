/*
考虑14_7_5中的类定义。
编写一个程序，使用标准C++
I/O、文件I/O以及14_7_5中定义的employee、manager、fink和highfink类型的数据。
该程序应包含count.cpp中的代码行，即允许用户将新数据添加到文件中。该程序首次运行时，将要求用户输入数据，然后
显示所有的数据，并将这些信息保存到一个文件中。当该程序再次被运行时，将首先读取并显示文件中的数据，然后让用户
添加数据，并显示所有的数据。差别之一是，应通过一个指向employee类型的指针数组来处理数据。这样，指针可以指向
employee对象，也可以指向从employee派生出来的其他三种对象中的任何一种。使数组较小有助于检查程序，例如，可以
将数组限定为最多包含10个元素：
const int MAX = 10;
...
employee * pc[MAX];
为通过键盘输入，程序应使用一个菜单，让用户选择要创建的对象类型。菜单将使用一个switch，以便使用new来创建指定
类型的对象，并将它的地址赋给pc数组中的一个指针。然后该对象可以使用虚函数setall()来提示用户输入相应的数据：
pc[i]->setall();
为将数据保存到文件中，应设计一个WriteAll();
for (i = 0; i < index; i ++)
    pc[i]->WriteAll(fout);

attention:
    应使用文本I/O，而不是二进制I/O（虚对象包含指向虚函数指针表的指针，而write()把这种信息复制到文件中。使用
    read()读取文件的内容，以填充对象时，函数指针值将为乱码，这将扰乱虚函数的行为）。可使用换行符将字段分隔开，
    这样在输入时将很容易识别各个字段。也可以使用二进制I/O，但不能将对象作为一个整体写入，而应该提供分别对每个
    类成员应用write()和read()的类方法。这样，程序将只把所需的数据保存到文件中。
使用文件恢复数据问题在于：程序如何才能知道接下来要恢复的项目是employee对象、manager对象、fink对象还是highfink
对象？一种方法是，在对象的数据写入到文件时，在数据前面加上一个指示对象类型的整数。这样在文件输入时，程序便可以
读取该整数，并使用switch语句创建一个适当的对象来接收数据：
    enum classkind{Employee, Manager, Fink, Highfink};
    ...
    int classtype;
    while ((fin >> classtype).get(ch)) //
fin首先将文件中的数字输出到classtype,然后再返回fin对象调用get(ch)
    // 将接下来的内容输出到ch
    {
        switch(classtype)
        {
            case Employee:
                pc[i] = new employee;
                break;
    然后便可以使用指针调用虚函数getall()来读取信息：
    pc[i++]->getall();
        }
    }
*/

enum classkind { Employee, Manager, Fink, Highflink };  // in class header

// 类声明
#include <fstream>
#include <iostream>
#include <string>

class abstr_emp {
 private:
  std::string fname;  // abstr_emp first name
  std::string lname;  // abstr_emp last name
  std::string job;

 public:
  abstr_emp();
  abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
  virtual void ShowAll() const;  // labels and shows all data
  virtual void SetAll();         // prompts user for values
  friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e);
  // just displays first and last name
  virtual void WriteAll(std::ofstream &fout);
  virtual void getall(std::ifstream &fin);
  virtual ~abstr_emp() = 0;  // virtual base class
};

class employee : public abstr_emp {
 public:
  employee();
  employee(const std::string &fn, const std::string &ln, const std::string &j);
  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::ofstream & fout);  // 将数据保存到文件中
  virtual void getall(std::ifstream &fin);
};

class manager : virtual public abstr_emp {
 private:
  int inchargeof;  // number of abstr_emp managed
 protected:
  int InChargeOf() const { return inchargeof; }  // output
  int &InChargeOf() { return inchargeof; }       // input
 public:
  manager();
  manager(const std::string &fn, const std::string &ln, const std::string &j,
          int ico = 0);
  manager(const abstr_emp &e, int ico);
  manager(const manager &m);
  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::ofstream &fout);
  virtual void getall(std::ifstream &fin);
};

class fink : virtual public abstr_emp {
 private:
  std::string reportsto;  // to whom fink reports
 protected:
  const std::string ReportsTo() const { return reportsto; }
  std::string &ReportsTo() { return reportsto; }

 public:
  fink();
  fink(const std::string &fn, const std::string &ln, const std::string &j,
       const std::string &rpo);
  fink(const abstr_emp &e, const std::string &rpo);
  fink(const fink &e);
  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::ofstream &fout);
  virtual void getall(std::ifstream &fin);
};

class highfink : public manager,
                 public fink  // management fink
{
 public:
  highfink();
  highfink(const std::string &fn, const std::string &ln, const std::string &j,
           const std::string &rpo, int ico);
  highfink(const abstr_emp &e, const std::string &rpo, int ico);
  highfink(const fink &f, int ico);
  highfink(const manager &m, const std::string &rpo);
  highfink(const highfink &h);
  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::ofstream &fout);
  virtual void getall(std::ifstream &fin);
};

// 类方法定义
// definition  of abstr_emp class and children
// abstr_emp/////////////////////////////////////////////////////
abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j) {
  fname = fn;
  lname = ln;
  job = j;
}

void abstr_emp::ShowAll() const {
  std::cout << "fname: " << fname << std::endl;
  std::cout << "lname: " << lname << std::endl;
  std::cout << "job: " << job << std::endl;
}

void abstr_emp::SetAll() {
  std::cout << "Please enter fname:  ";
  getline(std::cin, fname);
  std::cout << "Please enter lname:  ";
  getline(std::cin, lname);
  std::cout << "Please enter job:  ";
  getline(std::cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
  os << "fname: " << e.fname << std::endl;
  os << "lname: " << e.lname << std::endl;
  return os;
}

abstr_emp::~abstr_emp() {}

void abstr_emp::WriteAll(std::ofstream &fout) {
  fout << fname << std::endl;
  fout << lname << std::endl;
  fout << job << std::endl;
  // return fout;
}
void abstr_emp::getall(std::ifstream &fin) {
  (fin >> fname).get();
  (fin >> lname).get();
  (fin >> job).get();
  // return fin;
}

// employee/////////////////////////////////////////////////
employee::employee() {}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j)
    : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

void employee::WriteAll(std::ofstream &fout) {
  fout << (static_cast<int>(classkind::Employee)) << std::endl; // 将枚举转为整型
  abstr_emp::WriteAll(fout);
}

void employee::getall(std::ifstream &fin) { abstr_emp::getall(fin); }

// manager /////////////////////////////////////////////////
manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m) : abstr_emp(m) { inchargeof = m.inchargeof; }

void manager::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "inchargeof: " << inchargeof << std::endl;
}

void manager::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Please enter the inchargeof: ";
  std::cin >> inchargeof;
  while (std::cin.get() != '\n') continue;
}

void manager::WriteAll(std::ofstream &fout) {
  fout << static_cast<int>(classkind::Manager) << std::endl;
  abstr_emp::WriteAll(fout);
  fout << inchargeof << std::endl;
}

void manager::getall(std::ifstream &fin) {
  abstr_emp::getall(fin);
  (fin >> inchargeof).get();
}

// fink ////////////////////////////////////////////////////////
fink::fink() {}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j,
           const std::string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo)
    : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &e) : abstr_emp(e) { reportsto = e.reportsto; }

void fink::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "resportsto: " << reportsto << std::endl;
}

void fink::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Please enter the reportsto: ";
  getline(std::cin, reportsto);  // getline不会留下换行符
}

void fink::WriteAll(std::ofstream &fout) {
  fout << static_cast<int>(classkind::Fink) << std::endl;
  abstr_emp::WriteAll(fout);
  fout << reportsto << std::endl;
}

void fink::getall(std::ifstream &fin) {
  abstr_emp::getall(fin);
  (fin >> reportsto).get();
}

// highfink ////////////////////////////////////////////
highfink::highfink() {}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &f, int ico)
    : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager &m, const std::string &rpo)
    : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "InChargeof:" << manager::InChargeOf() << std::endl;
  std::cout << "reportsto" << fink::ReportsTo() << std::endl;
}

void highfink::SetAll() {
  abstr_emp::SetAll();
  int inchargeof;
  std::cout << "Please enter the inchargeof: ";
  std::cin >> inchargeof;
  manager::InChargeOf() = inchargeof;
  while (std::cin.get() != '\n') continue;
  std::string reporsto;
  std::cout << "Please enter the resportsto: ";
  getline(std::cin, reporsto);
  fink::ReportsTo() = reporsto;
}

void highfink::WriteAll(std::ofstream &fout) {
  fout << static_cast<int>(classkind::Highflink) << std::endl;
  abstr_emp::WriteAll(fout);
  fout << manager::InChargeOf() << std::endl;
  fout << fink::ReportsTo() << std::endl;
}

void highfink::getall(std::ifstream &fin) {
  abstr_emp::getall(fin);
  (fin >> manager::InChargeOf()).get();
  (fin >> fink::ReportsTo()).get();
}

// 主函数

const int MAX = 10;
int main() {
  std::cout << "Please enter the file's path" << std::endl;
  std::string filename;
  (std::cin >> filename).get();
  std::ifstream fin(filename);
  if (!fin.is_open())  // 文件不存在尝试读取文件错误，则新写入这个新文件
  {
    fin.close();
    std::ofstream fout(filename, std::ios::out | std::ios::app);
    abstr_emp *pc[MAX];
    int classtype1;
    int i = 0;
    for (; i < MAX; i++) {
      (std::cin >> classtype1).get();
      switch (static_cast<classkind>(classtype1)) {
        case classkind::Employee:
          pc[i] = new employee;
          break;
        case classkind::Manager:
          pc[i] = new manager;
          break;
        case classkind::Fink:
          pc[i] = new fink;
          break;
        case classkind::Highflink:
          pc[i] = new highfink;
          break;
        default:
          break;
      }
      pc[i]->SetAll();
      pc[i]->ShowAll();
      if (fout.good())
        std::cout << (void *) pc[i] << std::endl;
      pc[i]->WriteAll(fout);
    }
    for (int j = 0; j < i; j++)
      delete pc[j];
    fout.close();
  }
  else 
  {
    int classtype2, i = 0;
    abstr_emp * pc[MAX];
    while ((fin >> classtype2))
    {
      std::cout << classtype2;
      switch (static_cast<classkind>(classtype2))
      {
      case classkind::Employee:
        pc[i] = new employee;
        break;
      case classkind::Manager:
        pc[i] = new manager;
        break;
      case classkind::Fink:
        pc[i] = new fink;
        break;
      case classkind::Highflink:
        pc[i] = new highfink;
        break;
      default:
        break;
      }
      pc[i++]->getall(fin);
    }

    for (int j = 0; j < i; j ++)
    {
      pc[j]->ShowAll();
      delete pc[j];
    }
    fin.close();
  }

  return 0;
}

// const int MAX = 1;
// int main()
// {
//   abstr_emp * pc[MAX];
//   std::string filename;
//   std::cin >> filename;
//   std::ofstream fout(filename, std::ios::out | std::ios::app);
//   int classtype;
//   int i = 0;
//   for (; i < MAX; i ++)
//   {
//     (std::cin >> classtype).get();
//       switch (static_cast<classkind>(classtype)) {
//         case classkind::Employee:
//           pc[i] = new employee;
//           break;
//       default:
//         break;
//       }
//   pc[i]->SetAll();
//   pc[i]->ShowAll();
//   if (fout.good())
//     std::cout << (void *) pc[i] << std::endl;
//   pc[i]->WriteAll(fout);
//   }
//   fout.close();
//   return 0;
// }


// #inlude 包含的头文件中定义的优先级比直接在当前文件中定义的要高，
// 如果当前文件中类名与include的头文件相同则会类定义取头文件中的
// new type [] 与 delete [] 严格对应
// 即使是声明了一个指针数组（指针元素是单独new出来的）然后delete []这个数组，也是会报错，必须对
// 每个指针元素单独delete
// segmentation fault 内存访问越界，不恰当的输入也可能引起这个问题

