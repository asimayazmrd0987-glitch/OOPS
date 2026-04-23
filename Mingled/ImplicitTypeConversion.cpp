#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = a;           // int → double (safe promotion)
    cout << "b = " << b << endl;  // 10.0

    double x = 3.14;
    int y = x;               // double → int (demotion, loses fractional part)
    cout << "y = " << y << endl;  // 3 (warning: possible loss of data)

    // In expressions
    double result = 5 / 2;   // integer division first (5/2=2), then converted to double → 2.0
    cout << "result = " << result << endl;  // 2

    double correct = 5.0 / 2; // 2.5
    return 0;
}