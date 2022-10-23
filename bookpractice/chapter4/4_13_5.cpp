#include <iostream>
struct CandyBar
{
    char brand[30];
    float weight;
    unsigned int calorie;
};
int main()
{
    using namespace std;
    CandyBar snack = {
        "Mocha Munch",
        2.3,
        350
    };
    cout << "The brand is: " << snack.brand << endl;
    cout << "The weight is: " << snack.weight << endl;
    cout << "The calorie is: " << snack.calorie << endl;
    return 0;
}