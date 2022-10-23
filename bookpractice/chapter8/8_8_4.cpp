#include <iostream>
using namespace std;
#include <cstring> // for strlen(),strcpy()
struct stringy{
    char * str; // pointer to a string
    int ct; // length of string (not counting '\0')
};

// prototype for set(),show(),and show() go here
void show(const char * str,int n = 1);
void show(const stringy & beany,int n = 1);
void set(stringy & beany,const char * str);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany,testing); // first argument is a reference,
                    // allocates space to hold copy of testing,
                    // sets str member of beany to point to the
                    // new block,copies testing to new block,
                    // and sets ct member of beany
    show(beany);    // prints member string once
    show(beany,2);  // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing); // print testing string once
    show(testing,3); // prints testing string thrice
    show("Done!");
    return 0;
}

void show(const char * str,int n)
{
    for (int i =0;i<n;i++)
        cout << str << endl;
}

void show(const stringy & beany,int n)
{
    for (int i = 0;i<n;i++)
    {
        cout << beany.str << endl;
        cout << beany.ct << endl;
        cout << "\n";
    }
}
/*
void set(stringy & beany,const char * str)
{
    beany.ct = strlen(str);
    char * p = new char[beany.ct+1];
    for (int i = 0;i<beany.ct;i++)
        p[i] = str[i];
    p[beany.ct] = '\0';
    beany.str = p; 
}
*/
void set(stringy & beany,const char * str)
{
    int len = strlen(str);
    beany.str = new char[len+1];
    strcpy(beany.str,str);
    beany.ct = len;
}