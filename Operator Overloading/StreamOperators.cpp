// The left operand of << and >> is ostream or istream, not an object of your class. So they
//  must be overloaded as non‑member functions, typically friend to access private members.
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    // Declare friend functions
    friend ostream& operator<<(ostream& os, const Point& p);
    friend istream& operator>>(istream& is, Point& p);
};

// Overload << (output)
ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;   // return ostream to allow chaining (cout << a << b)
}

// Overload >> (input)
istream& operator>>(istream& is, Point& p) {
    cout << "Enter x and y: ";
    is >> p.x >> p.y;
    return is;   // return istream to allow chaining
}

int main() {
    Point p1(3, 4);
    cout << "p1 = " << p1 << endl;   // uses operator<<

    Point p2;
    cin >> p2;                         // uses operator>>
    cout << "You entered: " << p2 << endl;
    return 0;
}
// They return a reference to the stream to allow chaining (e.g., cout << a << b).
// operator<< should not modify the Point, so it takes const Point&.
// operator>> modifies the Point, so it takes Point&.