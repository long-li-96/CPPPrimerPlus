// values of expressions
#include <iostream>
int main()
{
    using namespace std;
    int x;
    
    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = "<< x << endl;
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    cout.setf(ios_base::boolalpha); // 使cout显示true和false，而不是1和0
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    return 0;
}