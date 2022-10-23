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
    CandyBar snacks[3] = {
        {"Mocha Munch", 2.3, 350},
        {"mocha", 2.4, 360},
        {"munch", 2.5, 370}
    };
    cout << "Brand: " << snacks[0].brand << endl;
    cout << "Weight: " << snacks[0].weight << endl;
    cout << "Calorie: " << snacks[0].calorie << endl;
    cout << endl;
    cout << "Brand: " << snacks[1].brand << endl;
    cout << "Weight: " << snacks[1].weight << endl;
    cout << "Calorie: " << snacks[1].calorie << endl;
    cout << endl;
    cout << "Brand: " << snacks[2].brand << endl;
    cout << "Weight: " << snacks[2].weight << endl;
    cout << "Calorie: " << snacks[2].calorie << endl;
    return 0;
}
