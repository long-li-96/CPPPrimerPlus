#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
    string brand;
    float weight;
    unsigned int calorie;
};
int main()
{
    CandyBar * snacks = new CandyBar [3];
    *snacks = {
        "ahgagj",
        1.545,
        4
    }; // 指向数组的指针，值为第一个元素的地址
    *(snacks+1) = {
        "ghakgh",
        4.04,
        1
    };
    *(snacks+2) = {
        "gagh",
        1,
        2
    };
    cout << "Brand: " << (*snacks).brand << endl;
    cout << "Weight: " << (*snacks).weight << endl;
    cout << "Calorie: " << (*snacks).calorie << endl;
    cout << "\n";
    cout << "Brand: " << (*(snacks+1)).brand << endl;
    cout << "Weight: " << (*(snacks+1)).weight << endl;
    cout << "Calorie: " << (*(snacks+1)).calorie << endl;
    cout << "\n";
    cout << "Brand: " << (*(snacks+2)).brand << endl;
    cout << "Weight: " << (*(snacks+2)).weight << endl;
    cout << "Calorie: " << (*(snacks+2)).calorie << endl;
    delete [] snacks;
    return 0;
}