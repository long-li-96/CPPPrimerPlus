#include "golf.h"
void setgolf(golf & g,const char * name,int hc)
{
    strcpy(g.fullname,name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    char name[Len];
    int hc;
    std::cout << "Please enter name:";
    std::cin.get(name, Len);
    std::cin.ignore(Len,'\n'); // 忽略'\n'
    std::cout << "Please enter hc: ";
    std::cin >> hc;
    std::cin.get();
    if (strcmp(name,"") == 0)
    {
        return 0;
    }
    else 
    {
        strcpy(g.fullname,name);
        g.handicap = hc;
        return 1;
    }
}

void handicap(golf & g,int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << "fullname: " << g.fullname << std::endl;
    std::cout << "handicap: " << g.handicap << std::endl;
}