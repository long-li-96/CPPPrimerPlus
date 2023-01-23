#include <iostream>
#include <cctype>
int main()
{
    using namespace std;
    char ch;
    cout << "Please enter one of the following choices: " << endl 
         << "c) carnivore" << "  p) pianist" << endl
         << "t) tree" << "  g) game" << endl;
    while(cin.get(ch) && true)
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
            while(cin.get() != '\n') // 读取缓冲区所有输入，直到遇到换行符
                continue;
            cout << "Please enter c,p,t or g: ";
        }
    }
    return 0;
}