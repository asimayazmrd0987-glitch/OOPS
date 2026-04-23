#include <iostream>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    // Constructor 1 — no arguments (default)
    Box() {
        length = width = height = 0.0;
        cout << "Default constructor called\n";
    }

    // Constructor 2 — one argument (cube: all sides equal)
    Box(double side) {
        length = width = height = side;
        cout << "Single-arg constructor called\n";
    }

    // Constructor 3 — three arguments (full dimensions)
    Box(double l, double w, double h) {
        length = l; width = w; height = h;
        cout << "Three-arg constructor called\n";
    }

    // Destructor — same name as class, prefixed with ~, no parameters, no return type
    // Automatically called when the object goes out of scope or is deleted
    ~Box() {
        cout << "Destructor called for Box("
             << length << "x" << width << "x" << height << ")\n";
    }

    double volume() const {
        return length * width * height;
    }
};
int main() {
    Box b1;              // calls Constructor 1 — default
    Box b2(5.0);         // calls Constructor 2 — cube 5x5x5
    Box b3(2.0, 3.0, 4.0); // calls Constructor 3 — full dimensions

    cout << "Volume of b3: " << b3.volume() << "\n";

    // Destructors are called automatically here when main() ends
    // Order: LIFO — b3 first, then b2, then b1
}
// ```

// **Output:**
// ```
// Default constructor called
// Single-arg constructor called
// Three-arg constructor called
// Volume of b3: 24
// Destructor called for Box(2x3x4)
// Destructor called for Box(5x5x5)
// Destructor called for Box(0x0x0)
// ```

// **Purpose of destructor and when it is invoked:**

// A **destructor** is a special member function that performs cleanup when an object's lifetime ends. Its job is to release any resources the object acquired — heap memory, file handles, network connections.

// It is invoked automatically in three situations:
// 1. When a local object goes **out of scope** (end of block `}`)
// 2. When a `delete` is called on a heap-allocated object (`delete ptr`)
// 3. When a program terminates normally

// It is never called manually. The compiler guarantees it runs exactly once per object, in reverse order of construction (LIFO).

// ---

// ## The Deep Why

// Constructor overloading is the same mechanism as function overloading — **the compiler resolves the call at compile time based on argument types and count.** Think of it as a routing table:
// ```
// Box()           → Constructor 1
// Box(double)     → Constructor 2
// Box(double,double,double) → Constructor 3