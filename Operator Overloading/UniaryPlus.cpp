#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
public:
    Vector2D(double x = 0) : x(x) {}

    // Unary plus: returns a copy
    Vector2D operator++() {
        return Vector2D(++x);   // return by value
    }
    Vector2D operator++(int) {
        return Vector2D(x++);
    }

    void display() const {
        cout << "(" << x << ")" << endl;
    }
};

int main() {
    Vector2D v1(3),v2;
    ++v1; //3 becomes 4
    v2 = ++v1;   // 4 becomes 5
    v2.display(); // now 5 is displayed
    return 0;
}
