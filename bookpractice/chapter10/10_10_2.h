// class definition for the Person
#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person
{
    private:
        static const int LIMIT = 25; // 同一个类的所有对象共享，全局变量
        std::string lname; 
        char fname[LIMIT];
    public:
        Person() {lname = ""; fname[0] = '\0';}
        Person(const std::string & ln, const char * fn = "Heyyou"); // 构造函数给默认值
        void Show() const;
        void FormalShow() const;
};

#endif