// testing the Stack class
#include <iostream>
#include <cctype> // or ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order, \n"
         << "P to process a P0, or Q to quit.\n";
    while( cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue; // 直到cin获取到缓冲区的换行符, 捕获缓冲区中的剩余字符
        if (!isalpha(ch))
        {
            cout << "\a";
            continue;   // 不是字符，继续输入
        }
        switch (ch)
        {
            case 'A': // 没有break，执行下一步代码
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                        cout << "stack already full\n";
                      else 
                        st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                        cout << "stack already empty\n";
                      else 
                      {
                        st.pop(po);
                        cout << "PO #" << po << " popped\n";
                      }
                      break;
        }
        cout << "Please enter A to add a purchase order, \n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
