#include "16_10_6.h"
#include <cstdlib> // for rand()

void Customer::set(long when)
{
    processtime = std::rand() % 3 +1;
    arrive = when;
}