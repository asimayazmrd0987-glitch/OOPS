#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& chai) const {
        return Complex(this->real + chai.real, this->imag + chai.imag);
    }
    void input() {
        cin >> real >> imag;
    }
        void display() const {
        cout << real << " + i" << imag;
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter complex number as real & imaginary: ";
    c1.input();
    cout << "Enter complex number as real & imaginary : ";
    c2.input();

    Complex c3 = c1 + c2;  

    cout << "The complex number is ";
    c3.display();
    return 0;
}