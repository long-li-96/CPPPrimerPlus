// defining, prototyping, and calling a function
#include <iostream>

void simple(); // function prototype
int main()
{
    using namespace std;
    cout << "main() will call the simple() function: \n";
    simple();  // function call
        cout << "main() is finished with simple() function.\n";
    return 0;
}

// function difinition
void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}