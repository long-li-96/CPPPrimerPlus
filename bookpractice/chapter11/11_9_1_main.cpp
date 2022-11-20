// using the Vector class
// compile with the vector.cpp file
#include <iostream>
#include <fstream> // for file I/O
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() time() prototype
#include "11_9_1.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream outFile; // create object for output
    outFile.open("/Users/kali/C++PrimerPlus/CaddaddPrimerPlus/testfile/11_9_1.txt"); // associate with a file
    if (!outFile.is_open()) // if failed to open file, then exit
    {
        cout << "Could not open the file " << "/Users/kali/C++PrimerPlus/CaddaddPrimerPlus/testfile/11_9_1.txt" << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        outFile << "Target Distance: " << target << ", Step Size: " << dstep << endl; 
        outFile << steps << ": ";
        outFile << result << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            outFile << steps << ": ";
            outFile << result << endl;
        }
        outFile << "After " << steps << " steps, the subject "
             << "has the following location:\n";
        outFile << result << endl;
        result.polar_mode();
        outFile << " or\n";
        outFile << result << endl;
        outFile << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}