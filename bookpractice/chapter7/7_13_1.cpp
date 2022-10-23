 #include <iostream>
 using namespace std;
 double avg_reciprocal(double x,double y);
 int main()
 {
     double x,y;
     cout << "Please enter the double x and y:" << endl;
     cin >> x >> y;
     while ( x!=0 & y!=0)
     {
         cout << avg_reciprocal(x,y);
         cin >> x >> y;
     }
    return 0;
 }
 double avg_reciprocal(double x,double y)
 {
     return 2.0*x*y/(x+y);
 }