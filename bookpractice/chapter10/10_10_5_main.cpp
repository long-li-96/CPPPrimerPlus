// testing the Stack1 class
#include <iostream>
#include <cctype>
#include "10_10_5.h"
int main()
{
    using namespace std;
    Stack1 st;
    char ch;
    Item po;
    cout << "Please enter A to add a customer, \n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << "\a";
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a':
                if (st.isfull())
                {
                    cout << "The order of 10 customers has been filed,"
                            << "Please process the existing order first!"
                         << endl;
                }
                else 
                {
                    cout << "Add customer name: ";
                    cin.getline(po.fullname,35);
                    cout << "Add the customer's consumption amount: ";
                    cin >> po.payment;
                    cin.get();
                    cout << "Add: " << st.push(po);
                }
                break;
            case 'p':
            case 'P':
                if (st.isempty())
                {
                    cout << "There are currently no unprocessed orders." << endl;
                }
                else 
                {
                    st.pop(po);
                }
                break;
            default:
                cout << "Input error!!!" << endl;
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}