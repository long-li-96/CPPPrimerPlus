#include <iostream>
struct students
{
    char first_name[20];
    char last_name[20];
    unsigned int age;
    char grade;
};
int main()
{   
    using namespace std;
    char letter_grade;
    students * bsy = new students; // 声明并初始化一个指针变量（分配内存地址）
    cout << "What is your first name?" << endl;
    cin.getline(bsy->first_name,20);
    cout << "What is your last name?" << endl;
    (cin >> bsy->last_name).get(); // 接收并消除换行符
    cout << "What letter grade do you deserve?" << endl;
    cin >> letter_grade;
    cout << "What is your age?" << endl;
    cin >> bsy->age; // cin只是使用换行符来确定字符串结束，不包括int，int要输入非结束符才会检测结束符
    bsy->grade = letter_grade + 1;
    cout << "Name: " << bsy->last_name << ", " << bsy->first_name << endl;
    cout << "Grade: " << bsy->grade << endl;
    cout << "Age: " << bsy->age << endl;
    return 0;
}