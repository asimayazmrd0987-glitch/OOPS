#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int a, b, c, d;   // [a b; c d]
public:
    Matrix2x2(int a_ = 0, int b_ = 0, int c_ = 0, int d_ = 0) : a(a_), b(b_), c(c_), d(d_) {}

    // Overload multiplication (matrix multiplication)
    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            a * other.a + b * other.c,
            a * other.b + b * other.d,
            c * other.a + d * other.c,
            c * other.b + d * other.d
        );
    }

    void display() const {
        cout << "[" << a << " " << b << "]\n";
        cout << "[" << c << " " << d << "]\n";
    }
};

int main() {
    Matrix2x2 m1(1,2,3,4), m2(2,0,1,2);
    Matrix2x2 m3 = m1 * m2;
    m3.display();
    return 0;
}