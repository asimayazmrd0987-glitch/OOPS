/*Operator overloading means giving new meaning to existing operators (like +, -, *, ==, etc.)
so they can work with user-defined data types (like objects of a class).
For example:
Normally, the + operator adds two numbers.
With operator overloading, you can make + also add two objects of a class, like combining 
two BankAccount objects or concatenating two String objects.*/
#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.2, 4.5), c2(1.1, 2.3);
    Complex c3 = c1 + c2;   // uses overloaded +
    c3.display();           // Output: 4.3 + 6.8i
    return 0;
}