#include <iostream>
const int field_number1 = 47;
const int choices = 5;
const int field_number2 = 27;
long double probability(unsigned field_number1, unsigned choices, unsigned field_number2);
int main()
{
    using namespace std;
    cout << "You have one chance in ";
    cout << probability(field_number1,choices,field_number2);
    cout << " of winning.\n";
    return 0;
}

long double probability(unsigned field_number1, unsigned choices, unsigned field_number2)\
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = field_number1, p = choices; p>0; n--, p--)
    {
        result = result * n / p;
    }
    return result * field_number2;
}