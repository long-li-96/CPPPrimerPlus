// emp.cpp -- methods for mi
 
#include "14_7_5.h"
 
using std::cout;
using std::cin;
using std::endl;
// methods for abstr_class
abstr_emp::abstr_emp() { }
 
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
              const std::string & j) : fname(fn), lname(ln), job(j) { }
void abstr_emp::ShowAll() const
{
    cout << "Name: " << lname << ", " << fname << endl;
    cout << "   Job: " << job << endl;
}
 
void abstr_emp::SetAll()
{
    cout << "Enter firstname: ";
    cin >> fname;
    cout << "Enter lastname: ";
    cin >> lname;
    while (cin.get() != '\n')
        continue;
    cout << "Enter job: ";
    getline(cin, job);
}
 
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.lname << ", " << e.fname;
    return os;
}
abstr_emp::~abstr_emp() { }         // is necessary
// methods for employee class
employee::employee() { }
employee::employee(const std::string & fn, const std::string & ln,
             const std::string & j) : abstr_emp(fn, ln, j) { }
void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    cout << "Category employee:\n";
    abstr_emp::SetAll();
}
 
// methods for employee class
manager::manager() { }
manager::manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico) : abstr_emp(fn, ln, j),
            inchargeof(ico) { }
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) { }
manager::manager(const manager & m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}
 
void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "   Number in charge of employees: " << inchargeof << endl;
}
 
void manager::SetAll()
{
    cout << "Category manager:\n";
    abstr_emp::SetAll();
    cout << "Enter number of in charge of employees: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}
 
// methods for fink class
fink::fink() { }
fink::fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j),
         reportsto(rpo) { }
fink::fink(const abstr_emp & e, const std::string & rpo) : 
        abstr_emp(e), reportsto(rpo) { }
fink::fink(const fink & f) : abstr_emp(f)
{
    reportsto = f.reportsto;
}
void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "   Reports to " << reportsto << endl;
}
void fink::SetAll()
{
    cout << "Category fink:\n";
    abstr_emp::SetAll();
    cout << "Enter repeorts to : ";
    getline(cin, reportsto);
}
 
// methods for highfink class
highfink::highfink() { }
highfink::highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
             fink(fn, ln, j, rpo) { }
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : 
             abstr_emp(e), manager(e, ico), fink(e, rpo) { }
 
highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m),
            manager(m), fink(m,rpo) { }
        
highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico),
            fink(f) { }
 
highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) { }
 
void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "   Number in charge of employees: " << manager::InChargeOf() << endl;
    cout << "   Reports to " << fink::ReportsTo() << endl;
}
 
void highfink::SetAll()
{
    cout << "Category highfink:\n";
    abstr_emp::SetAll();
    int temp_ico;
    cout << "Enter number of in charge of employees: ";
    cin >> temp_ico;
    manager::InChargeOf() = temp_ico;
    while (cin.get() != '\n')
        continue;
    std::string temp_rpo;
    cout << "Enter repeorts to : ";
    getline(cin, temp_rpo);
    fink::ReportsTo() = temp_rpo;
}