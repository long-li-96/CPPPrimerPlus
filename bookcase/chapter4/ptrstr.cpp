// using pointers to strings
#include <iostream>
#include <cstring> // declare strlen() strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";
    const char * bird = "wren"; // bird holds address of string, can use "wren" but not modify its value
    char * ps; // uninitialized
    cout << animal << " and " ;
    cout << bird << "\n";
    // cout << ps << "\n"; // may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal; // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps does't point to allocated space
    
    ps = animal;
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl; // cout display pointer's address except strings
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1]; 
    strcpy(ps,animal);  // copy string to new storage
    cout << "After using strcpy(): \n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;
    return 0;
}