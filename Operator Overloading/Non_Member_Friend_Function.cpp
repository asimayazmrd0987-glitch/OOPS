// Sometimes you may want to overload an operator as a friend function
//  (e.g., when the left operand is not an object of your class). For unary operators, 
//  it's less common, but possible.
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}

    // Declare friend function
    friend Point operator-(const Point& p);

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Definition of friend function
Point operator-(const Point& p) {
    return Point(-p.x, -p.y);
}

int main() {
    Point p1(5, -3);
    Point p2 = -p1;
    p2.display();   // (-5, 3)
    return 0;
}