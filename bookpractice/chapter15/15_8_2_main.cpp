// using exception classes

#include <cmath>
#include <iostream>

#include "15_8_2.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  double x, y, z;

  cout << "Enter two numbers: ";
  while (cin >> x >> y) {
    try {
      z = hmean(x, y);
      cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
      cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y)
           << endl;
      cout << "Enter next set of numbers <q to quit>: ";
    }

    catch (bad_hmean& bg) {
      bg.what();
      cout << "Try again.\n";
      continue;
    }

    catch (bad_gmean& hg) {
      hg.what();
      cout << "Sorry, you don't get to play any more.\n";
      break;
    }
    cout << "Bye!\n";
    return 0;
  }
}

double hmean(double a, double b) {
  if (a == -b) throw bad_hmean(__func__);
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0) throw bad_gmean(__func__);
  return std::sqrt(a * b);
}