// strong string1 as string2
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
#include <cctype>
#include <cstring>
using std::ostream;
using std::istream;

class String
{
    private:
        char * str;
        int len;
        static int num_strings; // number of objects
        static const int CINLIM = 80; // cin input limit
    public:
        // constructors and other methods
        String(const char * s);
        String();
        String(const String &);
        ~String();
        int length() const {return len;} // inline method
        void stringlow() const; // make the string to low
        void stringup() const; // make the string to up
        int has(const char & s) const; // count the number of a char in string

        // overloaded operator methods
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i); // 可能改变字符串
        const char & operator[](int i) const; // 不能改变字符串
        String operator+(const String & st) const;


        // overloaded operator friends
        friend bool operator<(const String & st1, const String & st2);
        friend bool operator>(const String & st1, const String & st2);
        friend bool operator==(const String & st1, const String & st2);
        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, String & st);
        friend String operator+(const char * s, const String & st);

        // static function
        static int HowMany();
};

#endif
