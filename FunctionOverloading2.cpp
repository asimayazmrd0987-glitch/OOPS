/*
 * INTERMEDIATE: Advanced Function Overloading
 * 
 * What you'll learn:
 * - Different parameter counts
 * - Default arguments interaction
 * - Reference vs value parameters
 * - const overloading
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Calculator {
public:
    // ============================================
    // Overload by number of parameters
    // ============================================
    
    // Multiply 2 numbers
    int multiply(int a, int b) {
        cout << "multiply(int, int): ";
        return a * b;
    }
    
    // Multiply 3 numbers
    int multiply(int a, int b, int c) {
        cout << "multiply(int, int, int): ";
        return a * b * c;
    }
    
    // ============================================
    // Overload by type (int vs double)
    // ============================================
    
    double multiply(double a, double b) {
        cout << "multiply(double, double): ";
        return a * b;
    }
    
    // ============================================
    // Overload by reference vs value
    // ============================================
    
    // Takes value (copy made)
    void process(int x) {
        cout << "process by value: " << x << endl;
        x = 999;  // Changes local copy only
    }
    
    // Takes reference (original modified)
    void process(int& x) {
        cout << "process by reference: " << x << endl;
        x = 888;  // Changes original!
    }
    
    // Takes const reference (read-only, efficient)
    void process(const int& x) {
        cout << "process by const reference: " << x << endl;
        // x = 777;  // ERROR: can't modify const
    }
};

// ============================================
// Default arguments - careful with overloading!
// ============================================

// BAD: Ambiguous with defaults
// void show(int a, int b = 10);
// void show(int a);  // Ambiguous: show(5) could call either!

// GOOD: Clear separation
void display(int a) {
    cout << "One arg: " << a << endl;
}

void display(int a, int b) {
    cout << "Two args: " << a << ", " << b << endl;
}

void display(string msg, int times = 1) {
    // Default argument - can call with 1 or 2 args
    for (int i = 0; i < times; i++) {
        cout << msg << " ";
    }
    cout << endl;
}

// ============================================
// const overloading (member functions)
// ============================================

class Array {
    int data[10];
public:
    // Non-const version: can modify
    int& get(int index) {
        cout << "Non-const get: ";
        return data[index];  // Returns reference, can assign to
    }
    
    // Const version: read-only
    // Called when object is const
    int get(int index) const {
        cout << "Const get: ";
        return data[index];  // Returns value, read-only
    }
};

int main() {
    Calculator calc;
    
    cout << "=== Overload by Count ===" << endl;
    cout << calc.multiply(2, 3) << endl;
    cout << calc.multiply(2, 3, 4) << endl;
    
    cout << "\n=== Overload by Type ===" << endl;
    cout << calc.multiply(2.5, 3.5) << endl;
    
    cout << "\n=== Value vs Reference ===" << endl;
    int num = 100;
    calc.process(num);           // Calls process(int&) - better match
    cout << "After process: " << num << endl;
    
    const int constNum = 200;
    calc.process(constNum);      // Calls process(const int&) - only option
    
    calc.process(300);           // Calls process(int) - temporary, needs value
    
    cout << "\n=== Default Arguments ===" << endl;
    display(42);
    display(10, 20);
    display("Hello");
    display("Hi", 3);
    
    cout << "\n=== Const Overloading ===" << endl;
    Array arr;
    const Array constArr;
    
    arr.get(0) = 5;              // Calls non-const get(), can assign
    int x = constArr.get(0);     // Calls const get(), read-only
    
    return 0;
}