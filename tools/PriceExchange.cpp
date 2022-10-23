#include <iostream>
using namespace std;
double dd373_exchange(double);
double dnf_exchange(double);

int main()
{
    double *dd373 = new double,*dnf = new double;
    cout << "dd373: ";cin >> *dd373;
    cout << "dnf: ";cin >> *dnf;
    *dd373 = dd373_exchange(*dd373);
    *dnf = dnf_exchange(*dnf);
    cout << "dd373: " << *dd373 << endl;
    cout << "dnf: " << *dnf << endl;
    delete dd373;
    delete dnf;
    system("pause");
    return 0;
}

double dd373_exchange(double dd373)
{
    return dd373/(100*0.979/0.97);
}

double dnf_exchange(double dnf)
{
    return 100/(dnf*0.95);
}