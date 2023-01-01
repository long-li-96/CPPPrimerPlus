// flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
    private:
        char * str; // pointer to string, 并没有为字符串本身分配存储空间
        int len; // length of string
        static int num_strings; // number of objects
    public:
        StringBad(const char * s); // constructor
        StringBad(); // default constructor
        ~StringBad(); // destructor
    // friend function
        friend std::ostream & operator<<(std::ostream & os,
        const StringBad & st);
};
#endif