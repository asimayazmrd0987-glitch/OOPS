#include <iostream>
using namespace std;
int c=12;
int main() {
    int a = 10, b = 20;
    cout<<::c<<endl; //resolution
    // Reference: fixed, cannot reseat
    int& ref = a;
    // ref = b;        // ERROR: this assigns b's value to a!
    cout << "ref to a: " << ref << endl;
    
    // Pointer: flexible, can reseat
    int* ptr = &a;
    ptr = &b;           // OK: now points to b
    *ptr = 30;          // changes b
    cout << "ptr now to b: " << *ptr << ", b=" << b << endl;
    
    return 0;
}
/*👉 Alias means another name for the same thing.
In C++, an alias gives a new name to:
a data type
a variable
a complex type
So code becomes easier to read.*/