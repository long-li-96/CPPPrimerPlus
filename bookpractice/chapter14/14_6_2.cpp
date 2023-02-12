#include <iostream>
using std::cout;
class Frabjous
{
private:
    char fab[20];

public:
    Frabjous(const char * s = "C++"): fab(s) {}
    virtual void tell() (cout << fab; )
};

class Glom 
{
private:
    int glip;
    Frabjous fb;

public:
    Glom(int g = 0, const char * s = "C++");
    Glom(int g, const Frabjous & f);
    void tell();
};

Glom::Glom(int g, const char * s): glip(g), fb(s)
{

}

Glom::Glom(int g, const Frabjous & f): glip(g), fb(f)
{

}

void Glom::tell()
{
    cout << glip << " ";
    fb.tell();
}


