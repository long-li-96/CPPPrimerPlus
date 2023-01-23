// testing the Stack class
#include <cctype>
#include "12_9_4.h"

int main()
{
    using namespace std;
    Stack st1(5);
    Stack st2 = st1;
    Stack st3(st2);
    unsigned long po;
    cin >> po;
    if (st1.isfull())
        cout << "stack already full\n";
    else 
        st1.push(po);
    if (st2.isempty())
        cout << "stack already empty\n";
    else
    {
        st2.pop(po);
        cout << "PO #" << po << " popped\n";
    }
    return 0;
}