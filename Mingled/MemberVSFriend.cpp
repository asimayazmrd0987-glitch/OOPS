class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}
    
    // Member function: left operand is implicitly the calling object
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex c1(3,4), c2(1,2);
    Complex c3 = c1 + c2;  // c1.operator+(c2)  ✅
    // Complex c4 = 5 + c1; // ❌ Error: 5 is not a Complex, can't call member on it
}
// Characteristics of member functions:
// Automatically have a this pointer pointing to the object they're called on.
// Can be declared const if they don't modify the object.
// Cannot be used when the left operand is not of the class type (e.g., 5 + obj).

