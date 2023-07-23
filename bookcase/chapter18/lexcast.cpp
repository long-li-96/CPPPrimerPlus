// simple cast from float to string
#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"
int main()
{
    using namespace std;
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string> (weight);
    gain = gain + wt + " to "; // string operator+()
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string> (weight) + ".";
    cout << gain << endl;
    return 0;
}
// 编译时需要指定boost的库文件路径和头文件路径，加上命令：-L /opt/homebrew/opt/boost/lib -I /opt/homebrew/opt/boost/include