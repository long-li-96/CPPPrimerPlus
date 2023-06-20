// having cin throw an exception
#include <iostream>
#include <exception>

int main()
{
    using namespace std;
    // have failbit cause an exception to be thrown
    cin.exceptions(ios_base::failbit); // cin捕获到failbit就抛异常,clear()与exceptions()返回值比较，均为failbit抛ios_base::failure
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try
    {
        while(cin >> input) // cin异常输入触发clear()
        {
            sum+=input;
        }
    }
    catch(ios_base::failure & bf)
    {
        std::cerr << bf.what() << endl;
        cout << "O! the horror!\n";
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}