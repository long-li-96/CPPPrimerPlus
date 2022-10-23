// a simple structure
#include <iostream>
struct inflatable // stucture declaration
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guest = 
    {
        "Glorious Gloria",
        1.88,
        29.99
    };
// It's initialized to the indicated values
    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    };
// NOTE: some implementations require using 
// static inflatable guset = 

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    return 0;
}