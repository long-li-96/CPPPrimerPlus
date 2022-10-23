// implementing the Bankaccount class
#include <iostream>
#include "10_10_1.h"

Bankaccount::Bankaccount()
{
    name = "no name";
    account = "00000000";
    savings = 0.00;
}

Bankaccount::Bankaccount(const std::string & na, const std::string & ac,
                         double pr)
{
    name = na;
    account = ac;
    savings = pr;
}

Bankaccount::~Bankaccount()
{
    
}

void Bankaccount::add(double num)
{
    savings += num; 
}

void Bankaccount::reduce(double num)
{
    savings -= num;
}

void Bankaccount::show()
{
    std::cout << "The account's name is: " << name << std::endl;
    std::cout << "The account is: " << account << std::endl;
    std::cout << "The account's savings is: " << savings << std::endl;
}