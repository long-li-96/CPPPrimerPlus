// shows hex[16] and octal[8] literals[常量],cout 默认以十进制显示整数
#include <iostream>
int main()
{
    using namespace std;
    int chest = 42; // decimal[10] integer literal
    int waist = 0x42; // hexadecimal[16] integer literal
    int inseam = 042; // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal) \n";
    cout << "waist = " << waist << " (0x42 in hex) \n";
    cout << "inseam = " << inseam << " (042 in octal) \n";
    return 0;
}