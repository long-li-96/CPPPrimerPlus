#include <iostream>
using namespace std;
const unsigned Size = 100;
struct CandyBar
{
    char names[Size];
    double weight;
    int heat;
};
void fill(CandyBar & candy, const char * name = "Millennium Munch",
          double weight = 2.85, int heat = 350);
void show(const CandyBar & candy);

int main()
{
    CandyBar candy;
    cout << "Enter the brand name of the candy bar: ";
    char name[Size];
    cin.getline(name,Size);
    fill(candy,name);
    show(candy);
    return 0;
}

void fill(CandyBar & candy, const char * name, double weight, int heat)
{
    int i = 0;
    while(name[i] && i < Size-1)
    {
        candy.names[i] = name[i];
        i++;
    }
    //candy.names = name; 地址不可变
    candy.weight = weight;
    candy.heat = heat;
}

void show(const CandyBar & candy)
{
    cout << candy.names << endl;
    cout << candy.weight << endl;
    cout << candy.heat << endl;
}