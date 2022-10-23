// Display the US population as a percentage of the global population
#include <iostream>
int main()
{
    using namespace std;
    long long global_population, us_population;
    double percentage;
    cout << "Enter the world's population: ";
    cin >> global_population;
    cout << "Enter the population of the US: ";
    cin >> us_population;
    percentage = double(us_population) / double(global_population);
    cout << "The population of the US is " << 100 * percentage << "%" << " of the world population.";
    return 0;
}