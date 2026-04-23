#include <iostream>
using namespace std;

class Box {
public:
    int length;

    Box(int l) : length(l) {}   // constructor

    // ✅ Overload the + operator
    Box operator+(const Box& other) {
        return Box(this->length + other.length);
    }
};

int main() {
    Box b1(5), b2(3);
    Box b3 = b1 + b2;   // calls your operator+ function!

    cout << b3.length;  // prints 8 ✅
}
