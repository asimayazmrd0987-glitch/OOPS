#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}

    // Prefix increment (++obj)
    Counter& operator++() {
        ++count;
        return *this;   // return reference to the updated object
    }

    // Postfix increment (obj++)
    Counter operator++(int) {
        Counter temp = *this;   // save current state
        ++count;                // increment
        return temp;            // return the old value (by value)
    }

    void display() const {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c1(5);

    cout << "Initial: ";
    c1.display();        // 5

    ++c1;                // prefix
    cout << "After ++c1: ";
    c1.display();        // 6

    Counter c2 = c1++;   // postfix
    cout << "After c1++: c1 = ";
    c1.display();        // 7
    cout << "c2 (old value) = ";
    c2.display();        // 6

    return 0;
}
// Prefix: operator++() returns a reference to the current object after incrementing. It's efficient and allows chaining (e.g., ++(++obj)).

// Postfix: operator++(int) takes a dummy int parameter to distinguish it. It returns the old value by value (a temporary), then increments.

