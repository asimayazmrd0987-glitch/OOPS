/*
 * INTERMEDIATE: Multiple Types & Auto Return
 * Different types, flexible returns
 */

#include <iostream>
using namespace std;

// Two different types allowed
template<typename T, typename U>
auto add(T a, U b) {
    // auto figures return type (int + double = double)
    return a + b;
}

// Non-type parameter: N is value, not type
template<typename T, int N>
T multiplyBy(T x) {
    return x * N;  // N known at compile time
}

int main() {
    // Mixed types
    cout << add(5, 3.2) << endl;      // int + double
    cout << add(2.5, 4) << endl;      // double + int
    
    // Compile-time constant
    cout << multiplyBy<int, 3>(10) << endl;  // 10 * 3
    cout << multiplyBy<double, 2>(5.5) << endl; // 5.5 * 2
    
    return 0;
}