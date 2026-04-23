class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}
    
    // Declare friend function
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
};

// Definition of friend function (no Complex:: prefix)
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
}

int main() {
    Complex c1(3,4), c2(1,2);
    Complex c3 = c1 + c2;   // operator+(c1, c2) ✅
    // Now you can also do:
    // Complex c4 = 5 + c1;   // ❌ Still not working because 5 is not Complex
}
// When to Use Member vs Friend for Operator Overloading
// Use Member Function When:
// The operator is unary (++, --, - (unary), !).
// The operator modifies the object itself (+=, -=, etc.) – often return reference.
// The left operand must be an object of your class, and you don't need implicit conversions on the left side (e.g., obj + something is fine, but something + obj is not required).
// Examples: +=, ++, =, [], ->, () must be members.
// Use Friend (or Non‑member) Function When:
// The operator is binary and you want symmetry (e.g., obj + 5 and 5 + obj).
// The left operand is not an object of your class (e.g., cout << obj – left is ostream).
// You need to access private members but cannot make the function a member (e.g., << and >>).
// You want to avoid implicit conversions on the left side causing ambiguity.
// Example: << and>> must be non‑member functions because the left operand is ostream/istream, not your class.