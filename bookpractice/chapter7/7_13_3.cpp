#include <iostream>
using namespace std;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void show_box(const box box1);
void cal_volume(box * box2);

int main()
{
    box box1;
    cout << "Please enter the data of box: " << endl;
    cout << "the maker: ";
    cin >> box1.maker;
    cin.clear();
    cout << "the height: ";
    cin >> box1.height;
    cout << "the width: ";
    cin >> box1.width;
    cout << "the length: ";
    cin >> box1.length;
    cal_volume(&box1);
    show_box(box1);
    return 0;
}

void show_box(const box box1)
{
    cout << "The data of box: " << endl;
    cout << "maker: " << box1.maker << endl;
    cout << "height: " << box1.height << endl;
    cout << "width: " << box1.width << endl;
    cout << "length: " << box1.length << endl;
    cout << "volume: " << box1.volume;
}

void cal_volume(box * box2)
{
    box2->volume = box2->height * box2->length * box2->width;
}