// food processing program
// use and display a variable
#include <iostream>
int main()
{
    using namespace std;
    int carrots;
    carrots = 25;
    cout << "I have "; //<<将后面的内容插入输出流
    cout << carrots;
    cout << "carrots.";
    cout << endl; //endl换行
    carrots-=1;
    cout << "Crunch,Crunch.Now I have " << carrots << " carrots." << endl;
    return 0;
}
