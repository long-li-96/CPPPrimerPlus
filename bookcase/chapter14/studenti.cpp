// Student class using private inheritance
#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods
double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else 
        return 0;
}

const string & Student::Name() const
{
    return (const string &) * this; // 强制转换为基类
}

double & Student::operator[](int i)
{
    return ArrayDb::operator[](i); // 使用基类的方法
}

double Student::operator[] (int i) const
{
    return ArrayDb::operator[] (i);
}

// private method
ostream & Student::arr_out(ostream & os) const
{
    int i ;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i ++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4) 
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// friends
// use String version of operator>>()
istream & operator>>(istream & is, Student & stu)
{
    is >> (string &) stu;
    return is;
}

// use string friend getline(ostream &, const string &)
istream & getline(istream & is, Student & stu)
{
    getline(is, (string & ) stu);
    return is;
}

// use string version of operator<<()
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (const string & ) stu << ":\n";
    stu.arr_out(os); //
    return os;
}