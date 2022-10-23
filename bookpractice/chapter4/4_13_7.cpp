#include <iostream>
struct pizza
{
    char companyname[30];
    float diameter;
    float weight;
};
int main()
{
    using namespace std;
    pizza p1;
    cout << "Enter the company name of pizza: " << endl;
    cin.getline(p1.companyname,30);
    cout << "Enter the diameter of pizza: " << endl;
    cin >> p1.diameter;
    cout << "Enter the weight of pizza: " << endl;
    cin >> p1.weight;
    cout << "The pizza's company name: " << p1.companyname << endl;
    cout << "The pizza's diameter: " << p1.diameter << endl;
    cout << "The pizza's weight: " << p1.weight;
    return 0; 
}