#include <iostream>
using namespace std;

class Meter {
    double value;
public:
    // Conversion constructor: int → Meter
    Meter(int m) : value(m) {
        cout << "Meter constructed from int\n";
    }
    // Constructor from double (also conversion)
    Meter(double m) : value(m) {}

    double get() const { return value; }
};

void printMeter(const Meter& m) {
    cout << m.get() << " meters\n";
}

int main() {
    Meter m1 = 10;        // int → Meter via conversion constructor (implicit)
    printMeter(20);        // int → Meter (implicit conversion for function argument)
    // To disable implicit conversion, mark constructor 'explicit' (see below)
}