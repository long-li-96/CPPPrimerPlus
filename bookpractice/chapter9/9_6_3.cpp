// using placement new
#include <iostream>
#include <cstring> // for strcpy()
#include <new> // for placement new
struct chaff
{
    char dross[20];
    int slag;
};
const int N = 2;
chaff chaffs[N];
void display(const chaff * chaffs);
using namespace std;
int main()
{
    int i = 0;
    char str[20];
    //指针数组不可修改？
    chaff * pd1 = new (chaffs) chaff[N]; // 将pd1分配到chaffs数组中; 
    chaff * pd2  = new chaff[N];
    for (i = 0;i<N;i++)
    {
        cout << "请输入pd1中的第" << i << "个chaff的字符串：\n";
        cin >> str;
        cin.get();
        strcpy(pd1[i].dross,str); //结构中的字符串不应用指针取
        cout << "输入pd1中的第" << i << "个chaff的数字：\n";
        cin >> pd1[i].slag;
        cin.get();

        cout << "请输入pd2中的第" << i << "个chaff的字符串：\n";
        cin >> str;
        cin.get();
        strcpy(pd2[i].dross,str);
        cout << "输入pd2中的第" << i << "个chaff的数字：\n";
        cin >> pd2[i].slag;
        cin.get();
    }
    //cout << pd1 << endl;
    //cout << pd2;
    display(pd1);
    display(pd2);
    return 0;
}

void display(const chaff * chaffs)
{
    for (int i = 0;i<N;i++)
    {
        cout << chaffs[i].dross << endl;
        cout << chaffs[i].slag << endl;
    }
}