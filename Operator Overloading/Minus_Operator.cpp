#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}

    // Overload unary minus (-)
    Number operator-() const {
        // Create a new Number with negated value
        return Number(-value);
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n1(10);
    Number n2 = -n1;   // Calls operator- on n1

    n1.display();      // 10
    n2.display();      // -10
    return 0;
}
// operator-() is a member function taking no parameters (unary).

// It returns a new Number object with the negated value.

// The original object remains unchanged.