#include "11_9_6.h"
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>
// prototypes
Stonewt max_stonewts(const Stonewt * s, int num);
Stonewt min_stonewts(const Stonewt * s, int num);
int judge_stonewts(const Stonewt * s, int num, const Stonewt & c);

// main function
int main()
{
    using namespace std;
    srand(time(0)); // seed random-number generator
    Stonewt stonewts[6] = {
        Stonewt(17.5),
        Stonewt(11.5),
        Stonewt(0.5)
    };
    double lbs;
    for (int i = 0;i < 3;i++)
    {
        cout << "Enter the " << i + 4
        << "stonewt" << endl;
        while (!(cin >> lbs))
            cout << "Please enter the correct" 
            "double value !" << endl;
        stonewts[i + 3] = Stonewt(lbs);     
    }
    Stonewt j = Stonewt(11, 0.0);
    cout << "The max stonewt is " << max_stonewts(stonewts, 6) << endl;
    cout << "The min stonewt is " << min_stonewts(stonewts, 6) << endl;
    cout << "Stonewts'num larger than or equal to 11 stone are: " <<
    judge_stonewts(stonewts, 6, j) << endl;
    return 0;
}

Stonewt max_stonewts(const Stonewt * s, int num)
{
    //int total_num = sizeof(*s);
    Stonewt max_stonewt = s[0];
    for (int i = 1; i < num; i ++)
    {
        if (*(s + i) > max_stonewt)
            max_stonewt = *(s +i);
    }
    return max_stonewt;
}

Stonewt min_stonewts(const Stonewt * s, int num)
{
    //int total_num = sizeof(*s);
    Stonewt min_stonewt = s[0];
    for (int i = 0; i < num; i ++)
    {
        if (*(s+i) < min_stonewt)
            min_stonewt = *(s+i);
    }
    return min_stonewt;
}

int judge_stonewts(const Stonewt * s, int num, const Stonewt & c)
{
    //int total_num = sizeof(*s);
    Stonewt ar[num];
    int j = 0;
    for (int i = 0; i < num; i ++)
    {
        if (*(s+i) >= c)
        {
            j += 1;
        }
    }
    return j;
}