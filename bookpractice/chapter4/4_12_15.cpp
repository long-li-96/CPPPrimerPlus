#include <iostream>
struct fish
{
    char kind[20];
    int weight;
    float length;
};
int main()
{
    using namespace std;
    fish * f1 = new fish;
    cin.get(f1->kind, 20); //直接赋值字符串，输入长度比函数参数大时会报错
    f1->length = 1.5;
    f1->weight = 1;
    cout << f1->kind << endl;
    cout << f1->length << endl;
    cout << f1->weight << endl;
    delete f1;
    cout << f1->kind;
    return 0;
}