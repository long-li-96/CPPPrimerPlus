#include <iostream>
#include <string>
using namespace std;
struct pizza
{
    string companyname;
    float diameter;
    float weight;
};
int main()
{
    pizza *p1 = new pizza;
    cout << "Enter the diameter of pizza: " << endl;
    (cin >> p1->diameter).get();
    cout << "Enter the company name of pizza: " << endl;
    getline(cin,p1->companyname);
    cout << "Enter the weight of pizza: " << endl;
    cin >> p1->weight;
    cout << "Company name: " << p1->companyname << endl;
    cout << "Diameter: " << p1->diameter << endl;
    cout << "Weight: " << p1->weight;
    delete p1;
    return 0;
}