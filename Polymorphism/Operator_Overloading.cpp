#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Overload + operator
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Overload << for easy printing
    friend ostream& operator << (ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
    
    // Overload == operator
    bool operator == (const Complex& other) {
        return (real == other.real && imag == other.imag);
    }
};

int main() {
    Complex c1(3.0, 2.0), c2(1.0, 4.0);
    Complex c3 = c1 + c2;  // Calls operator+
    
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3 (c1+c2): " << c3 << endl;
    
    return 0;
}