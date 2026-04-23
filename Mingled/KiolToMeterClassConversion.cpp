#include <iostream>
using namespace std;

class Meters;  // forward declaration

class Kilometers {
    double value;
public:
    Kilometers(double km) : value(km) {}

    // Conversion operator: Kilometers -> Meters
    operator Meters() const;   // defined after Meters is known
    void display() const { cout << value << " km\n"; }
};

class Meters {
    double value;
public:
    Meters(double m) : value(m) {}
    void display() const { cout << value << " m\n"; }

    // Allow Kilometers to access our private constructor if needed?
    // Not needed if we use public constructor.
};

// Define conversion operator after Meters is complete
Kilometers::operator Meters() const {
    return Meters(value * 1000.0);
}

int main() {
    Kilometers km(3.7);
    Meters m = km;          // implicit conversion using operator Meters()
    m.display();            // 3700 m
    return 0;
}