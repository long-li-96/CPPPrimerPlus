// using the Stock class
// compile with stock10.cpp
#include <iostream>
#include "stock10.h"

int main()
{
    // {}决定自动变量stock1、stock2的所属代码块
    // 代码块执行完，则stock1、stock2执行析构
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);  // syntax 1
        stock1.show();

        Stock stock2("Boffo Objects", 2, 2.0); // syntax 2
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
        cout << "Revised stock:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}