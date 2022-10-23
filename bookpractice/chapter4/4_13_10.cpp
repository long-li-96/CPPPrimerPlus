#include <iostream>
#include <array>
int main()
{
    using namespace std;
    array<float,4> arr;
    cout << "Enter your first score: " << endl;
    cin >> arr[0];
    cout << "Enter your second score: " << endl;
    cin >> arr[1];
    cout << "Enter your third score: " << endl;
    cin >> arr[2];
    arr[3] = (arr[0]+arr[1]+arr[2])/3;
    cout << "You have " << 3 << " score" << endl;
    cout << "The average of your scores is " << arr[3] << endl;
    return 0; 
}