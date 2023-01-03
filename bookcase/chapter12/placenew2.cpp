// new, placement new, no delete
// 使用定位new运算符在相邻的内存单元中创建两个对象，并调用了合适的析构函数
#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesing
{
    private:
        string words;
        int number;

    public:
        JustTesing(const string & s = "Just Tesing", int n = 0)
        {
            words = s;
            number = n;
            cout << words << " constructed\n";
        }

        ~JustTesing()
        {
            cout << words << " destroyed\n";
        }

        void Show() const 
        {
            cout << words << ", " << number << endl;
        }
};

int main()
{
    char * buffer = new char[BUF]; // get a block of memory

    JustTesing * pc1, * pc2;

    pc1 = new (buffer) JustTesing; // place object in buffer
    pc2 = new JustTesing("Heap1", 20); // place object on heap

    cout << "Memory block addresses:\n" << "buffer: "
         << (void *) buffer << " heap: " << pc2 << endl;
    cout << "Memory contents: \n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesing * pc3, * pc4;
    // fix placement new location
    pc3 = new (buffer + sizeof(JustTesing))
              JustTesing("Better Idea", 6);
    pc4 = new JustTesing("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2; // free Heap1
    delete pc4; // free Heap2
    // explicitly destroy placement new objects
    pc3->~JustTesing(); // destroy object pointed to by pc3
    pc1->~JustTesing(); // destroy object pointed to by pc1
    // 仅当所有对象都被销毁后，才能释放用于存储这些对象的缓冲区
    delete [] buffer; // free buffer
    cout << "Done\n";
    return 0;
}