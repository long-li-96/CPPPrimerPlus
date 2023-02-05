// testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st; // create an empty stack
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"
         << "p to process a PO, or Q to quit.\n";
    
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue; // char不是字母继续这个大循环
        }

        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                        cout << "stack already full\n";
                      else
                        st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                        cout << "stack already empty";
                      else
                        {
                            st.pop(po);
                            cout << "PO #" << " popped\n";
                            break;
                        }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";

    }
    cout << "Bye\n";
    return 0;
}