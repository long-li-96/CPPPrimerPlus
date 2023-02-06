// testing stack of pointers
#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime>

#include "stcktp1.h"

const int Num = 10;

int main()
{
    std::srand(std::time(0)); // randomize rand()
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;

    // create an empty stack with stacksize slots
    Stack<const char *>st(stacksize);

    // in basket
    const char * in[Num] = {
        "1: Hank Gilfamesh","2: Kiki Ishtar",
        "3: Betty", "4: Ian",
        "5: Wolf", "6: Port",
        "7: Joy", "8: Xaver",
        "9: Juan","10: Misha"
    };

    // out basket

    const char * out[Num];

    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]); // 从in basket 放进 stack
        else if (st.isfull())
            st.pop(out[processed ++]); // stack满了则从stack取出放入out basket
        else if (std::rand() % 2  && nextin < Num) // 50-50 chance
            st.push(in[nextin ++]);
        else 
            st.pop(out[processed ++]);
    }
    for (int i = 0; i < Num; i ++)
        std::cout << out[i] << std::endl;
    std::cout << "Bye\n";
    return 0;
}