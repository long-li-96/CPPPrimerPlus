#include "13_11_3.h"
#include <string>
#include <cstring>
const int NUM = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DMA * p_dma[NUM];
    std::string temp;    
    int rat;

    char kind; // 互动选择创建的对象属于哪个类

    for (int i = 0; i < NUM; i ++)
    {
        cout << "Enter dma's label: ";
        getline(cin, temp);
        // string 转 char数组
        char * temp_str = new char[temp.size() + 1];
        std::strcpy(temp_str, temp.c_str());
        cout << "Enter dma's rating: ";
        cin >> rat;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA,"
             << "or 3 for hasDMA: ";
        while (cin >> kind && (kind != '1' && 
        kind != '2' && kind != '3'))
            cout << "Enter 1, 2, 3: ";
        cin.clear();
        if (kind == '1')
            p_dma[i] = new baseDMA(temp_str, rat);
        else if (kind == '2')
        {
            std::string temp1;
            cout << "Enter lacksdma's color: ";
            getline(cin, temp1);
            char * temp1_str = new char[temp1.size() + 1];
            std::strcpy(temp1_str, temp1.c_str());
            p_dma[i] = new lacksDMA(temp1_str, temp_str, rat);
        }
        else
        {
            std::string temp1;
            cout << "Enter lacksdma's style: ";
            getline(cin, temp1);
            char * temp1_str = new char[temp1.size() +  1];
            std::strcpy(temp1_str, temp1.c_str());
            p_dma[i] = new hasDMA(temp1_str, temp_str, rat);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;

    for (int i = 0; i < NUM; i ++)
    {
        p_dma[i]->View();
        cout << endl; 
    }

    for (int i = 0; i < NUM; i ++)
        delete p_dma[i];
    
    cout << "Done.\n";
    return 0;
}