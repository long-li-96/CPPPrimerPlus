// definition  of abstr_emp class and children
#include "14_7_5.h"
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

// employee/////////////////////////////////////////////////
employee::employee() {}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j)
    : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

// manager /////////////////////////////////////////////////
manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager & m): abstr_emp(m)
{
  inchargeof = m.inchargeof;
}

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
  getline(std::cin, reportsto); // getline不会留下换行符
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


void highfink::ShowAll() const
{
  abstr_emp::ShowAll();
  std::cout << manager::InChargeOf() << std::endl;
  std::cout << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
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

