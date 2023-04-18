// applying the STL to a string 
// string使用STL接口

#include <string>
#include <iostream>
#include <algorithm> // for next_permutation()

int main()
{
    using namespace std;
    string letters, letters_tmp;
    int num = 0;
    cout << "Enter the letter grouping (quit to quit): ";
    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        letters_tmp = letters;
        sort(letters.begin(), letters.end()); // 初始化为第一种排序方式
        cout << letters << endl;
        while (next_permutation(letters.begin(), letters.end())) // next_permutation()每次都就地排序，返回true或false
        {
            cout << letters << endl;
            num++;
        }
        cout << "Permutations of " << letters_tmp << "'s num " << num << endl;
        cout << "Enter next sequence (quit to quit): ";
    }
    cout << "Done.\n";
    return 0;
}