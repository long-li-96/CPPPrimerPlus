// using the Bankaccount class
#include <iostream>
#include "10_10_1.h"

const int SA = 4;

int main()
{
    Bankaccount bankaccounts[SA] = 
    {
        Bankaccount(),
        Bankaccount("test", "000000001", 0.01),
        Bankaccount(),
        Bankaccount("develop", "00000002", 0.02)
    };
    bankaccounts[0].show();
    bankaccounts[1].add(0.01);
    bankaccounts[3].reduce(0.01);
    bankaccounts[1].show();
    bankaccounts[3].show();
    return 0;
}