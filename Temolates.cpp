/*
 * FUNCTION TEMPLATES: Write once, use for any type
 * Key idea: Compiler generates code for each type you use
 *  What is a Function Template?
 * - Blueprint for creating functions
 * - Works with ANY data type
 * - Compiler generates specific version automatically
 * 
 * Analogy: Cookie cutter makes cookies of any dough (int, double, string)
 */

#include <iostream>
#include <string>
using namespace std;

// Template: T is placeholder for any type
template<typename T>
T add(T a, T b) {           // Works for int, double, string, etc.
    return a + b;
}

// Multiple types: T and U can be different
template<typename T, typename U>
auto multiply(T a, U b) {   // auto figures out return type
    return a * b;
}

int main() {
    // Compiler creates add<int>, add<double>, add<string>
    cout << add(3, 4) << endl;           // int: 7
    cout << add(2.5, 3.5) << endl;       // double: 6
    // cout << add(string("Hello"), "World") << endl;  // string
    
    // Different types: int * double = double
    cout << multiply(5, 2.5) << endl;    // 12.5
    
    return 0;
}