// using the Vector class
// compile with the vector.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() time() prototype
#include "11_9_3.h"
int main()
{
    using namespace std;
    //using VECTOR::Vector;
    using namespace VECTOR;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int N;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter the number of times of test: ";
        if (!(cin >> N))
            break;
        double steps_N[N];
        for(int i = 0; i < N; i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            steps_N[i] = steps;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        cout << "After " << N << " tests, the max of steps in test: "
             << max_ar(steps_N, N) << endl;
        cout << "the min of steps in test: " << min_ar(steps_N, N) << endl;
        cout << "the average of steps in test: " << ave_ar(steps_N, N) << endl;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}