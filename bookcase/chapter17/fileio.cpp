// saving to a file
#include <iostream> // not needed for many systems
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;

    cout << "Enter name for new file: ";
    cin >> filename;

    // create output stream object for new file and call it fout
    ofstream fout(filename.c_str());  // 从程序中输出到文件中

    fout << "For your eyes only!\n"; // write to file
    cout << "Enter your secret number: "; // write to screen
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close(); // close file

    // create input stream object for new file and call it fin
    ifstream fin(filename.c_str()); // 从文件中读取到程序中
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch)) // read character from file and 
        cout << ch; // write it to screen
    fin.close();

    return 0;
}