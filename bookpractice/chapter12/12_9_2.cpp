// methods for the class String
#include "12_9_2.h"


// initializing static class member
int String::num_strings = 0;

// static method 
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)
{
    len = std::strlen(s); 
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings ++;
}

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings ++;
}

String::String(const String & st)
{
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
    num_strings ++;
}

String::~String()
{
    delete [] str;
    num_strings --;
}

void String::stringlow() const
{
    // char * str_temp;
    // std::strcpy(str_temp, str);
    for (int i = 0; str[i]; i ++)
    {
        str[i] = std::tolower(str[i]);
    }
}

void String::stringup() const
{
    // char * str_temp;
    // std::strcpy(str_temp, str);
    for (int i = 0; str[i]; i++)
    {
        str[i] = std::toupper(str[i]);
    }
}

int String::has(const char & s) const
{
    int s_num = 0;
    for (int i = 0; str[i]; i ++)
    {
        if (str[i] == s)
            s_num ++;
    }
    return s_num;
}

// overloaded operator methods
    // assign a String to a String
String & String::operator=(const String & st)
{
    if (this == & st)
        return * this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return * this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return * this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String String::operator+(const String & st) const
{
    char str_temp[String::CINLIM];
    std::strcpy(str_temp, str);
    std::strcat(str_temp, st.str);
    return String(str_temp);
}

// overloaded operator friends
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n') // 一直读取直到读取到换行符
        continue;
    return is;
}

String operator+(const char * s, const String & st)
{
    char str_temp[String::CINLIM];
    std::strcpy(str_temp, s);
    std::strcat(str_temp, st.str);
    return String(str_temp);
}
