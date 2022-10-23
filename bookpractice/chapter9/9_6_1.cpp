#include "golf.h"
int main()
{
    golf gol[5];

    for (int i = 0;i<5;i++)
    {
        char name[Len];
        int hc;
        int result = 1;
        if (i%2 == 0)
        {
            result = setgolf(gol[i]);
        }
        else
        {
            std::cin.get(name,Len);
            std::cin.ignore(Len,'\n');
            std::cout << "Please enter hc: ";
            std::cin >> hc;
            std::cin.get();
            setgolf(gol[i],name,hc);
            if (strcmp(name,"") == 0)
                result = 0;
        }
        if (result == 0)
            break;
        if (i == 3)
            handicap(gol[i],7);
        showgolf(gol[i]);
    }
    return 0;
}