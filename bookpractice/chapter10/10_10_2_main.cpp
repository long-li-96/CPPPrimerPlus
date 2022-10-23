// using the Person class
#include <iostream>
#include "10_10_2.h"

int main()
{
    Person one;
    Person two("Smythecraft");
    Person threee("Dimwiddy", "Sam");
    two.Show();
    std::cout << std::endl;
    one.FormalShow();
}