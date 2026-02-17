/*
 * BEGINNER: Function Overloading Basics
 * 
 * What is Function Overloading?
 * - Same function name, different parameters
 * - Compiler chooses which version to call
 * - Like "print" can print int, double, or string
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================
// Three versions of "add" - same name, different parameters
// ============================================

// Version 1: add two integers
int add(int a, int b) {
    cout << "Calling int add: ";
    return a + b;
}

// Version 2: add two doubles
double add(double a, double b) {
    cout << "Calling double add: ";
    return a + b;
}

// Version 3: add three integers
int add(int a, int b, int c) {
    cout << "Calling three-int add: ";
    return a + b + c;
}

// ============================================
// Three versions of "print" - same name, different types
// ============================================

void print(int x) {
    cout << "Integer: " << x << endl;
}

void print(double x) {
    cout << "Double: " << x << endl;
}

void print(string s) {
    cout << "String: " << s << endl;
}

int main() {
    cout << "=== Function Overloading Demo ===" << endl;
    
    // Compiler picks right version based on arguments
    cout << add(3, 4) << endl;           // Calls int add(int, int)
    cout << add(3.5, 4.2) << endl;       // Calls double add(double, double)
    cout << add(1, 2, 3) << endl;        // Calls int add(int, int, int)
    
    cout << "\n=== Print Overloading ===" << endl;
    print(42);                           // Calls print(int)
    print(3.14);                         // Calls print(double)
    print("Hello");                      // Calls print(string)
    
    // Why overload? Same operation, different data types
    // No need to remember: addInt, addDouble, addThree...
    
    return 0;
}