#include <iostream>
const int strsize = 50;
using namespace std;
int main()
{
    struct bop{
        char fullname[strsize]; // real name
        char title[strsize]; // job title
        char bopname[strsize]; // secret BOP name
        int preference; // 0 = fullname, 1 = title, 2 = bopname
    };
    char ch;
    bop guests[3]=
    {
        {"david","junior programmer","MIPS",1},
        {"alice","senior programmer","LOOPY",2},
        {"jason","junior programmer","TOP",0}
    };
    cout << "Benevolent order of programmers report"<< endl
         << "a. display by name  " << "b. display by title" <<endl
         << "c. display by bopname  " << "d. display by preference" << endl
         << "q. quit" <<endl;
    while (cin>> ch)
    {
        cin.clear();
        if (ch == 'q')
        {
            break;
        }
        if ((ch == 'a')||(ch == 'b')||(ch == 'c')||(ch=='d'))
        {
            switch(ch)
            {
            case 'a': 
                      for (int i = 0;i<3;i++)
                      {
                        cout << guests[i].fullname << endl;
                      }
                      cout << "Next choice: ";
                      break;
            case 'b': 
                      for (int i = 0;i<3;i++)
                      {
                        cout << guests[i].title << endl;
                      }
                      cout << "Next choice: ";
                      break;
            case 'c': 
                      for (int i = 0;i<3;i++)
                      {
                        cout << guests[i].bopname << endl;
                      }
                      cout << "Next choice: ";
                      break;
            case 'd': 
                      for (int i=0;i<3;i++)
                      {
                        if (guests[i].preference==0)
                            cout << guests[i].fullname << endl;
                        else if(guests[i].preference == 1)
                            cout << guests[i].title << endl;
                        else 
                            cout << guests[i].bopname << endl;
                     }
                      cout << "Next choice: ";
                      break;
            }
        }
        else 
        {
            cout << "\nwrong input" << endl;
        }
        
    }
    return 0;
}
