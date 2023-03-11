// Person class(ABC), Gunslinger class, PokerPlayer class, BadDude class

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person{
    private:
        std::string family_name;
        std::string personal_name;
    protected:
        virtual void Data() const;
        virtual void Get();
    public:
        Person() {};
        Person(const char * fname, const char * pname): 
            family_name(fname), personal_name(pname) {}
        virtual void Show() const;
        virtual ~Person() = 0;
};

class Gunslinger: virtual public Person
{
    private:
        
    public:

};

#endif