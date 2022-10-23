#include <iostream>
#include <cctype>
int main()
{
    using namespace std;
    char ch;
    cout << "Please enter one of the following choices: " << endl 
         << "c) carnivore" << "  p) pianist" << endl
         << "t) tree" << "  g) game" << endl;
    while(cin.getline(ch,2)&&true)
    {
        switch(ch)
        {
            case 'c': cout << "carnivore";
                      break;
            case 'p': cout << "pianist";
                      break;
            case 't': cout << "tree";
                      break;
            case 'g': cout << "game";
                      break;
            default:
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Please enter c,p,t or g: ";
        }
    }
    return 0;
}